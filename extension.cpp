#include "extension.h"
//#include "CEconItemAttributeDefinition.h"


//class CEconItemSchema {};


ExtTF2SchemaTools g_Ext;
SMEXT_LINK(&g_Ext);


/* Source interfaces */
ICvar *icvar            = nullptr;
//IFileSystem *filesystem = nullptr;

/* function pointers */
//CEconItemSchema * (*GetItemSchema)() = nullptr;
//bool (CEconItemSchema:: *CEconItemSchema_BInitAttributes)(KeyValues *, CUtlVector<CUtlString> *) = nullptr;
//// TODO: CEconItemAttributeDefinition::BInitFromKV

/* struct offsets */
//// CUtlMap<int, CEconItemAttributeDefinition> *CEconItemSchema_m_AttributeDefinitions = nullptr;
//// >>>> Linux: probably @ +0x188

/* SourceMod config files */
//IGameConfig *g_pGameConf = nullptr;


//#define TRY_LOAD_FUNCPTR(signame, funcptr) \
//	if (!g_pGameConf->GetMemSig(signame, reinterpret_cast<void **>(&funcptr)) || funcptr == nullptr) { \
//		g_pSM->LogError(myself, "Failed to locate memory address based on signature for \"" signame "\"!"); \
//		success = false; \
//	} else { \
//		g_pSM->LogMessage(myself, "Found \"" signame "\" @ 0x%08x", *reinterpret_cast<uintptr_t *>(&funcptr)); \
//	}


bool ExtTF2SchemaTools::SDK_OnLoad(char *error, size_t maxlen, bool late)
{
//	if (!gameconfs->LoadGameConfigFile("TF2SchemaTools", &g_pGameConf, error, maxlen)) {
//		return false;
//	}
	
	bool success = true;
//	TRY_LOAD_FUNCPTR("GetItemSchema",                    GetItemSchema);
//	TRY_LOAD_FUNCPTR("CEconItemSchema::BInitAttributes", CEconItemSchema_BInitAttributes);
	return success;
}

void ExtTF2SchemaTools::SDK_OnUnload()
{
//	gameconfs->CloseGameConfigFile(g_pGameConf);
}

void ExtTF2SchemaTools::SDK_OnAllLoaded()
{
}


bool ExtTF2SchemaTools::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
	g_pCVar = icvar;
	ConVar_Register(0, this);
	
//	GET_V_IFACE_CURRENT(GetFileSystemFactory, filesystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
	
	return true;
}

bool ExtTF2SchemaTools::SDK_OnMetamodUnload(char *error, size_t maxlen)
{
	return true;
}


bool ExtTF2SchemaTools::RegisterConCommandBase(ConCommandBase *pCommand)
{
	META_REGCVAR(pCommand);
	return true;
}


#if 0
#define KV_FILE "addons/sourcemod/configs/ItemSchemaOverride.kv"
CON_COMMAND(itemschemaoverride_add_attrs, "Add custom item attribute definitions from " KV_FILE)
{
	KeyValues *kv_root = new KeyValues("ItemSchemaOverride");
	
	if (!kv_root->LoadFromFile(filesystem, KV_FILE, nullptr, true)) {
		Warning("Could not load " KV_FILE "!\n");
		kv_root->deleteThis();
		return;
	}
	
	KeyValues *kv_attr = kv_root->FindKey("attributes");
	if (kv_attr == nullptr) {
		Warning("No \"attributes\" subkey found in " KV_FILE "!\n");
		kv_root->deleteThis();
		return;
	}
	
	CUtlVector<CUtlString> errors;
	if (!(GetItemSchema()->*CEconItemSchema_BInitAttributes)(kv_attr, &errors)) {
		Warning("CEconItemSchema::BInitAttributes returned false!\n");
		for (auto& error : errors) {
			Warning("- %s\n", error.Get());
		}
		kv_root->deleteThis();
		return;
	}
	
	Msg("Success.\n");
	kv_root->deleteThis();
}
#endif
