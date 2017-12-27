//This is the main file
#include "grid.h"
#include "cell.h"
#include <string>
#include "textdisplay.h"



int main() {
	Grid g;
	
	while (true) {
		cin >> cmd;
		if (cmd == "new") {
			int size;
			cin >> size;
			g.init(size);
		}
		if (cmd == "play"){
			int x,y;
			cin >> x >> y;
			g.use(x,y);
		}
	}
}