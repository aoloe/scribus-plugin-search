# scribus-plugin-search

Implementing search and replace as a plugin

This is also the first try to get qtquick into a Scribus plugin.

(If you want to know why I'm interested in exploring qtquick, have a look at [Introducing Qt Quick Controls in Qt 5.1](https://www.youtube.com/watch?v=_6_F6Kpjd-Q).)

# Resources

- for an example on qt quick in scribus see:
      void ScribusMainWindow::testQTQuick2_1()

## Install

Clone the `scribus-plugin-search` repository and put – or symlink – its `src` directory into `scribus/plugins/` as `epub`. Then add 

    ADD_SUBDIRECTORY(search)

to `CMakeList.txt` file in `scribus/plugins/export/`.
