#!/bin/bash

# Usage: ./create_exercise_branches.sh <exercise_number>
if [ -z "$1" ]; then
    echo "Usage: $0 <exercise_number>"
    exit 1
fi

EX_NUM="$1"

for NAME in kent fowler farely deming; do
    BRANCH="${NAME}_exercise_${EX_NUM}"
    git checkout main || exit 1
    git checkout -b "$BRANCH" || exit 1
    git push --set-upstream origin "$BRANCH" || exit 1
done

git checkout main
