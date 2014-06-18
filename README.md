# scribus-plugin-search

implementing search and replace as a plugin

# Resources

- for an example on qt quick in scribus see:
      void ScribusMainWindow::testQTQuick2_1()

## Install

Clone the `scribus-plugin-search` repository and put – or symlink – its `src` directory into `scribus/plugins/` as `epub`. Then add 

    ADD_SUBDIRECTORY(search)

to `CMakeList.txt` file in `scribus/plugins/export/`.
