
// - (void)sendEvent:(NSEvent *)event;
static void sendEvent_IDEApplication(IDEApplication *self_, SEL _Sel, NSEvent *_pEvent)
{
	if (_pEvent.type == NSEventTypeKeyDown)
	{
		unsigned short keyCode = [_pEvent keyCode];
		NSUInteger ModifierFlags = [_pEvent modifierFlags];

		if (handleFieldEditorEvent(keyCode, ModifierFlags, _pEvent))
			return;
	}

	return ((void (*)(IDEApplication *self_, SEL _Sel, NSEvent *_pEvent))original_sendEvent_IDEApplication)(self_, _Sel, _pEvent);
}
