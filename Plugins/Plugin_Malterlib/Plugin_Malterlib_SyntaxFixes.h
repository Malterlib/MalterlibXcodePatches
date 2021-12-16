
NSLock<NSLocking> *g_SourceModelParseLock = nil;

// - (void)parse;
static void SMSourceModel_parse(id self_, SEL _Sel)
{
	// Protect against race conditions

	[g_SourceModelParseLock lock];
	((void(*)(id, SEL))original_SMSourceModel_parse)(self_, _Sel);
	[g_SourceModelParseLock unlock];
}
