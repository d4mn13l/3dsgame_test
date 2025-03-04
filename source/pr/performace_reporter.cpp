#include "performace_reporter.hpp"


void PerformanceReporter::_tick(float delta) {
	Node::_tick ( delta ) ; 
	if ( log_to_bottom_screen ) { 
		printf("\x1b[10;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
		printf("\x1b[11;1HGPU:     %6.2f%%\x1b[K", C3D_GetDrawingTime()*6.0f);
		printf("\x1b[12;1HCmdBuf:  %6.2f%%\x1b[K", C3D_GetCmdBufUsage()*100.0f);
	} 
}

