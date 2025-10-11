#!/usr/bin/env bash
set -euo pipefail

# Usage:
#   ./create_exercise_branches.sh <exercise_number> [-f|--force]
#
# Example:
#   ./create_exercise_branches.sh 1
#   ./create_exercise_branches.sh 1 -f   # move tag if it already exists

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

# --- Preconditions -----------------------------------------------------------
git rev-parse --is-inside-work-tree >/dev/null 2>&1 || {
  echo "Error: not inside a git repository." >&2
  exit 1
}

if ! git diff --quiet || ! git diff --cached --quiet; then
  echo "Error: working tree has uncommitted changes. Commit/stash first." >&2
  exit 1
fi

git remote get-url origin >/dev/null 2>&1 || {
  echo "Error: remote 'origin' not found." >&2
  exit 1
}

# --- Sync main & tags --------------------------------------------------------
echo "▶ Fetching latest state..."
git fetch --tags origin
git checkout main
git pull --ff-only origin main

# --- Create or update tag ----------------------------------------------------
if git rev-parse -q --verify "refs/tags/${TAG_NAME}" >/dev/null; then
  if [[ "${FORCE_TAG}" == "true" ]]; then
    echo "▶ Updating existing tag ${TAG_NAME} to current main..."
    git tag -fa "${TAG_NAME}" -m "Exercise ${EX_NUM} snapshot"
  else
    echo "ℹ Tag ${TAG_NAME} already exists (use -f to move it)."
  fi
else
  echo "▶ Creating tag ${TAG_NAME}..."
  git tag -a "${TAG_NAME}" -m "Exercise ${EX_NUM} snapshot"
fi

# Push tag (force if needed)
echo "▶ Pushing tag ${TAG_NAME}..."
if [[ "${FORCE_TAG}" == "true" ]]; then
  if ! git push --force origin "refs/tags/${TAG_NAME}"; then
    echo "⚠ Force push blocked; trying delete+recreate on remote..."
    git push origin ":refs/tags/${TAG_NAME}"
    git push origin "refs/tags/${TAG_NAME}"
  fi
else
  git push origin "refs/tags/${TAG_NAME}"
fi

# --- Create & push branches --------------------------------------------------
echo "▶ Creating and pushing branches from ${TAG_NAME}..."
for NAME in "${TEAM_NAMES[@]}"; do
  BRANCH="${NAME}${BRANCH_SUFFIX}"
  echo "  • ${BRANCH}"
  git branch -f "${BRANCH}" "${TAG_NAME}"
  git push -u origin "${BRANCH}" --force-with-lease
done

git checkout main

# --- List remote verification ------------------------------------------------
echo ""
echo "✅ Done. Created/updated tag '${TAG_NAME}' and branches:"
printf '   %s\n' "${TEAM_NAMES[@]/%/${BRANCH_SUFFIX}}"

echo ""
echo "🌐 Remote verification:"
git ls-remote --heads origin | grep "${TAG_NAME}" || true
git ls-remote --tags origin | grep "${TAG_NAME}" || true

echo ""
echo "Use this to inspect manually:"
echo "  🔹 https://github.com/<your_org>/<your_repo>/branches/all"
echo "  🔹 https://github.com/<your_org>/<your_repo>/tags"
