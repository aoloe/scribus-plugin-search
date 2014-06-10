/**
 * This is the entry point for the plugin.
 * All the methods defined here are called by Scribus' plugin execution code.
 */

#ifndef SEARCHPLUGIN_H
#define SEARCHPLUGIN_H

#include "pluginapi.h"
#include "scplugin.h"

class QString;
class ScribusDoc;
class ScribusMainWindow;

class PLUGIN_API SearchPlugin : public ScActionPlugin
{
	Q_OBJECT
public:

	SearchPlugin();
	virtual ~SearchPlugin();
	virtual bool run(ScribusDoc* doc=0, QString filename = QString::null);
	virtual const QString fullTrName() const;
	virtual const AboutData* getAboutData() const;
	virtual void deleteAboutData(const AboutData* about) const;
	virtual void languageChange();
	virtual void addToMainWindowMenu(ScribusMainWindow *) {};
};

extern "C" PLUGIN_API int searchplugin_getPluginAPIVersion();
extern "C" PLUGIN_API ScPlugin* searchplugin_getPlugin();
extern "C" PLUGIN_API void searchplugin_freePlugin(ScPlugin* plugin);

#endif
