#!/bin/bash

lint_opt="-fix"
for file in $(find . -name "*.cc" -o -name "*.h"); do
  clang-tidy-6.0 $file -p build/compile_commands.json $lint_opt
  clang-format-6.0 -i -style=file $file
done

