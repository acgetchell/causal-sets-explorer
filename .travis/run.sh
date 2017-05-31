#!/bin/bash

if [[ "$(uname -s)" == 'Darwin' ]]; then
    # Run with native OSX
    .travis/run_project_build.sh
else
    # Run with docker
    docker run -v$(pwd):/home/conan $DOCKER_IMAGE bash -c "pip install conan --upgrade && .travis/run_project_build.sh"
fi