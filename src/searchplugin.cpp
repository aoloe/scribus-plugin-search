#include <QDebug>
#include "search.h"
#include "searchplugin.h"
// #include "ui/searchdialog.h"

#include "scribuscore.h"
#include "scribusdoc.h"

// #include "ui/multiprogressdialog.h"

int searchplugin_getPluginAPIVersion()
{
	return PLUGIN_API_VERSION;
}

ScPlugin* searchplugin_getPlugin()
{
	SearchPlugin* plug = new SearchPlugin();
	Q_CHECK_PTR(plug);
	return plug;
}

void searchplugin_freePlugin(ScPlugin* plugin)
{
	SearchPlugin* plug = dynamic_cast<SearchPlugin*>(plugin);
	Q_ASSERT(plug);
	delete plug;
}

SearchPlugin::SearchPlugin() : ScActionPlugin()
{
	// Set action info in languageChange, so we only have to do
	// it in one place.
	languageChange();
}

SearchPlugin::~SearchPlugin()
{
	// unregisterAll();
};

void SearchPlugin::languageChange()
{
    qDebug() << "chuilala";
	// Note that we leave the unused members unset. They'll be initialised
	// with their default ctors during construction.
	// Action name
	m_actionInfo.name = "AleSearchAndReplace";
	// Action text for menu, including accel
	m_actionInfo.text = tr("&AleSearch and replace...");
	// Menu
	m_actionInfo.menu = "Extras";
	m_actionInfo.enabledOnStartup = false;
	m_actionInfo.needsNumObjects = -1;
}

const QString SearchPlugin::fullTrName() const
{
	return QObject::tr("Search and Replace");
}

const ScActionPlugin::AboutData* SearchPlugin::getAboutData() const
{
	AboutData* about = new AboutData;
	about->authors = "Ale Rimoldi <a.l.e@ideale.ch>";
	about->shortDescription = tr("Search and Replace");
	about->description = tr("Search and replace throught the document.");
	about->license = "GPL";
	Q_CHECK_PTR(about);
	return about;
}

void SearchPlugin::deleteAboutData(const AboutData* about) const
{
	Q_ASSERT(about);
	delete about;
}

bool SearchPlugin::run(ScribusDoc* doc, QString target)
{
	Q_ASSERT(target.isNull());
	ScribusDoc* currDoc=doc;
	if (currDoc == 0)
		currDoc = ScCore->primaryMainWindow()->doc;
	if (currDoc == 0)
		return false;

    SearchOptions options;

    Search *search = new Search();
    search->doSearch();
    // search->doSearchAndReplace();

    return true;

    /*
	SearchDialog *dialog = new SearchDialog(currDoc->scMW(), currDoc, "dlg", true, 0);
    dialog->setOptions(options);
	if (dialog)
	{
        if (dialog->exec() == QDialog::Accepted)
        {

            options = dialog->getOptions();
            // qDebug() << "options:" << options;
            Search *search = new Search();

            search->setScribusDocument(currDoc);
            search->setOptions(options);
            search->doSearchAndReplace();

            delete search;
        }
		delete dialog;
		return true;
	}
	else
		return false;
    */
}
