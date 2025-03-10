#include "performance_reporter.hpp"
#include "3dsgame.hpp"

void PerformanceReporter::_tick(float delta) {
	Node::_tick ( delta ) ; 
	if ( !preferences::enable_bottom_screen ) { 
		printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
		printf("\x1b[3;1HGPU:     %6.2f%%\x1b[K", C3D_GetDrawingTime()*6.0f);
		printf("\x1b[4;1HCmdBuf:  %6.2f%%\x1b[K", C3D_GetCmdBufUsage()*100.0f);
		printf("\x1b[5;1HUsed Mem:%6.2f / %6.2f\x1b[K", ((double)osGetMemRegionFree(MEMREGION_APPLICATION)) / 1000000, ((double)osGetMemRegionSize(MEMREGION_APPLICATION)) / 1000000);
	} 
}

