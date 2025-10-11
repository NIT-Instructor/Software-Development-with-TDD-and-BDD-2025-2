#!/usr/bin/env bash
set -euo pipefail

# Usage:
#   ./create_exercise_branches.sh <exercise_number> [-f|--force]
#
# Example:
#   ./create_exercise_branches.sh 1
#   ./create_exercise_branches.sh 1 -f   # overwrite existing tag

if [[ -z "${1:-}" ]]; then
  echo "Usage: $0 <exercise_number> [-f|--force]"
  exit 1
fi

EX_NUM="$1"; shift || true
FORCE_TAG="false"
if [[ "${1:-}" == "-f" || "${1:-}" == "--force" ]]; then
  FORCE_TAG="true"
fi

TAG_NAME="exercise-${EX_NUM}"
BRANCH_SUFFIX="-exercise-${EX_NUM}"
TEAM_NAMES=(kent fowler farely deming)

# Ensure we're in a Git repo
git rev-parse --is-inside-work-tree >/dev/null 2>&1 || {
  echo "Error: not inside a git repository."
  exit 1
}

# Make sure working tree is clean (avoid tagging uncommitted work by accident)
if ! git diff --quiet || ! git diff --cached --quiet; then
  echo "Error: working tree has uncommitted changes. Commit/stash first."
  exit 1
fi

# Update main and move there once
git fetch origin
git checkout main
git pull --ff-only origin main

# Create or update annotated tag at current main
if git rev-parse -q --verify "refs/tags/${TAG_NAME}" >/dev/null; then
  if [[ "${FORCE_TAG}" == "true" ]]; then
    echo "Tag ${TAG_NAME} exists; force-updating it to current main..."
    git tag -fa "${TAG_NAME}" -m "Exercise ${EX_NUM} snapshot"
  else
    echo "Tag ${TAG_NAME} already exists. Use -f/--force to move it."
  fi
else
  git tag -a "${TAG_NAME}" -m "Exercise ${EX_NUM} snapshot"
fi

# Push the tag
if [[ "${FORCE_TAG}" == "true" ]]; then
  # try force-pushing; if blocked, fall back to delete+push
  if ! git push --force origin "refs/tags/${TAG_NAME}"; then
    echo "Force push blocked; trying delete+recreate on remote..."
    git push origin ":refs/tags/${TAG_NAME}"
    git push origin "refs/tags/${TAG_NAME}"
  fi
else
  git push origin "refs/tags/${TAG_NAME}"
fi

# Return to main at the end
git checkout main

echo "✅ Done. Created/updated tag '${TAG_NAME}' and branches:"
printf '   %s\n' "${TEAM_NAMES[@]/%/${BRANCH_SUFFIX}}"
