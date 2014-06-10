#include <QDebug>

#include "search.h"
#include "scribusdoc.h"

#include "module/scribusAPIDocument.h"
#include "module/searchEpubfile.h"
#include "module/searchStructure.h"
#include "module/searchContent.h"

Search::Search()
{
    // progressDialog = 0;
    // itemNumber = 0;

    // qDebug() << "marksList" << this->doc->get()->marksList();
    // qDebug() << "notesList" << this->doc->get()->notesList();
}

Search::~Search()
{
}

void Search::doSearch()
{
    // qDebug() << "options" << options;
}

QDebug operator<<(QDebug dbg, const SearchOptions options)
{
    dbg.nospace() << "(targetFilename:" << options.targetFilename;
    QStringList output;
    foreach (int pageRange, options.pageRange) {
        output << QString::number(pageRange);
    }
    dbg.nospace() << ", (" << output.join(", ") << ")" << ", imageMaxWidth:" << options.imageMaxWidth  << ", imageMaxWidthThreshold:" << options.imageMaxWidthThreshold << ")";
    return dbg.space();
}
