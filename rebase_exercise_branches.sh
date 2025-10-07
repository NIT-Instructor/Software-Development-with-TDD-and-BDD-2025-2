#!/bin/bash

# Usage: ./rebase_exercise_branches.sh <exercise_number>
if [ -z "$1" ]; then
    echo "Usage: $0 <exercise_number>"
    exit 1
fi

EX_NUM="$1"

# Update local main
git checkout main || exit 1
git pull origin main || exit 1

for NAME in kent fowler farely deming; do
    BRANCH="${NAME}_exercise_${EX_NUM}"
    # Make sure branch exists locally
    if git show-ref --quiet refs/heads/"$BRANCH"; then
        git checkout "$BRANCH" || exit 1
    else
        git fetch origin "$BRANCH":"$BRANCH" || exit 1
        git checkout "$BRANCH" || exit 1
    fi

    git rebase main || { echo "Rebase failed for $BRANCH"; exit 1; }
    git push --force-with-lease origin "$BRANCH" || exit 1
done

git checkout main
