#!/bin/bash

# Workaround for https://github.com/travis-ci/travis-ci/issues/6307
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  gpg2 --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3
  rvm get stable --auto-dotfiles
  brew update
fi