Introduction
============

Embedded Unit is unit testing framework for Embedded C System.
Its design was copied from JUnit and CUnit and more, and then adapted somewhat for Embedded C System.
Embedded Unit does not require std C libs. All objects are allocated to const area.

This guide is tightly scoped with one purpose; to get you started with unit testing your embedded C code.

Getting Started
===============

1. Download EmbUnit from project site.

2. Extract the package.

Project Structure:

| embunit
| ├── embunit
| ├── samples
| ├── tests
| └── textui
| ├── tools
| │   ├── tbcuppa
| │   ├── tbuma

3. run make in embUnit root.

4. run make in textui folder.

5. You are done. You have two libraries in the new lib -folder; *libembunit.a* and *libtextui.a*