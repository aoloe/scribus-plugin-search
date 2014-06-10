/**
 * This is the main epub export class.
 * It gets called from the plugin class after the options have been set in the dialog
 */
#ifndef EPUBEXPORT_H
#define EPUBEXPORT_H

#include <QObject>

class ScribusDoc;
class MultiProgressDialog;

struct SearchOptions
{
    QString targetFilename;
    QList<int> pageRange;
    int imageMaxWidth;
    int imageMaxWidthThreshold;
    SearchOptions()
    {
        targetFilename = "";
        imageMaxWidth = 0;
        imageMaxWidthThreshold = 0;
    }
};

class Search : public QObject
/*
 * Inspired by svgexplugin
 */
{
    Q_OBJECT

public:
	Search();
	~Search();

	SearchOptions options;
    void setOptions(SearchOptions options) { this->options = options; }

    void setScribusDocument(ScribusDoc* scribusDoc) { this->scribusDoc = scribusDoc; }
	void doSearch();

public slots:
    void cancelRequested();

private:

    ScribusDoc* scribusDoc;

};

QDebug operator<<(QDebug dbg, const SearchOptions options);

#endif // EPUBEXPORT_H
