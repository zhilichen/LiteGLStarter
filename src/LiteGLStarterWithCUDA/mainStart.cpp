#include "ui/FlowController.h"
#include "common/common.h"

using namespace LGS;

int main(int argc, char **argv){
	
	BasicConfig config("mainConfig.xml");

	FlowController fc;
	fc.StartUI(config);

	return 0;
}