# NIT TDD

## WSL Setup

You need two terminals: first for running docker and second for running vscode  

Make sure that Docker is running in first terminal:

```sudo dockerd```

In second terminal open

```code .```  

In VSCode on startip in right bottom side click on Reopen in Container or control + shift + P -> Reopen in devcontainer to start a devcontainer.  

Devcontainer will span a docker image and install needed extensions in VSCode.

## USE ONLY TERMINAL IN VSCODE

It is connected to the docker.
Running scripts on local termanl will not work.

## Scripts

* build.sh used to build a project
* run.sh used to execute all tests
* clean.sh clean a project
* execute.sh build and run

https://github.com/matepek/vscode-catch2-test-adapter?tab=readme-ov-file

## SetUp  

## Install docker

```sh
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc
echo   "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
    $(. /etc/os-release && echo "$VERSION_CODENAME") stable" |   sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
sudo docker run hello-world

```

## Kent Beck

Kent Beck, one of the key figures in software development and the primary author behind Test-Driven Development (TDD). Here’s a concise summary about him:

Profession: Software engineer, author, and software methodology pioneer
Notable contributions:
Extreme Programming (XP): Kent Beck is one of the original creators of XP, an agile software development methodology.
Test-Driven Development (TDD): He popularized TDD, which emphasizes writing tests before writing the actual code.
JUnit: Co-creator of JUnit, the widely used testing framework for Java.
Books: He wrote influential books like “Test-Driven Development: By Example” and “Extreme Programming Explained”.
In short, Kent Beck is a major figure in modern software engineering, especially in the areas of agile practices, automated testing, and TDD.
