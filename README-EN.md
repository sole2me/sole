# sole
sole is a light-weight workflow and Business Process Management (BPM) Platform targeted at business people, developers and system admins based on Tars framework. Its core is a super-fast and rock-solid BPMN 2 process engine for C++. It's open-source and distributed under the MIT license.Sole can run in any application, server, cluster or cloud based on the Tars framework.It integrates perfectly with Tars framework it is extremely lightweight and based on simple concepts.

## Supported operating systems

> * Linux

## Supported programming languages

> * C、C++、Java、PYthon、NodeJS、PHP

## Documents

For API usage, see [proxy_api_guide-en.md](docs-en/proxy_api_guide-en.md),for more details, see [docs](docs-en/).
## Installation

See [install-en.md](docs/install.md)

## Overview Of Project Directories

Directory |Role
------------------|----------------
src/Utils         |Common code shared by all services
src/TarsComm      |Internal tars protocol
src/Parser        |Sole syntax parser
src/Grammar       |Sole parser
src/Engine        |Sole runtime engine
src/DataServer    |Data center services
src/FlowServer    |Data flow service
src/WorkServer    |Control flow service
src/EventServer   |Event service

* ```docs-en``` : Documentation