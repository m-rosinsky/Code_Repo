# Code_Repo / C / Threadpool

This contains a generic threadpool implementation.

### About

This threadpool is designed to create a set number of threads upon instantiation.

Upon cleanup, the threadpool allows any jobs still remaining on its queue to be completed before memory is cleaned up and threads are joined.

### Usage

See `main.c` for example program.

### Code Style

All code follows Barr-C coding standards with Doxygen commenting.
