//This is the main file
#include "Grid.h"
#include <string>



int main() {
	Grid g;
	cout << "Welcome" << endl;
	string cmd;
	
	while (true) {
		cin >> cmd;
		if (cmd == "new") {
			int size;
			cin >> size;
			g.init(size);
			cout << g;
		}
		if (cmd == "play"){
			int x,y,z;
			cin >> x >> y >> z;
			g.use(x,y,z);
			cout << g;
		}
		if (cmd == "end"){
			return 0;
		}
	}
}