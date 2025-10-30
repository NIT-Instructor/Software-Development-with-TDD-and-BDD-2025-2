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
# About Martin Fowler

**Martin Fowler** is a renowned software engineer, author, and speaker, best known for his contributions to software development and agile methodologies.  
His work has significantly influenced the industry, particularly in the areas of:

- **Refactoring:** Fowler's book *Refactoring: Improving the Design of Existing Code* is a seminal work that introduced developers to systematic techniques for enhancing code quality without altering its functionality.  
- **Patterns and Practices:** He has popularized many design patterns, including enterprise patterns like Domain-Driven Design (DDD) and the concept of Microservices.  
- **Agile Development:** As one of the original signatories of the Agile Manifesto, Fowler has been a strong proponent of iterative development and adaptive planning.

## Key Contributions

### Books and Writing
Fowler has authored and co-authored several influential books, including:  
- *Refactoring: Improving the Design of Existing Code*  
- *Patterns of Enterprise Application Architecture*  
- *Continuous Delivery* (with Jez Humble)  
- *Domain-Specific Languages*  
- *UML Distilled: A Brief Guide to the Standard Object Modeling Language*  

### Thought Leadership
His blog [martinfowler.com](https://martinfowler.com/) and public talks provide valuable insights into modern software practices and trends.

### Promoting Best Practices
He champions principles like **Test-Driven Development (TDD)**, **Continuous Integration**, and **Infrastructure as Code**, shaping how modern software teams work and collaborate.

---

✨ *Martin Fowler continues to inspire software developers worldwide with his innovative ideas and dedication to advancing the craft of programming.*