#include<iostream>
#include<string>
#include"Header.h"
using namespace std;

int main()
{	
	
	AdgList<string> ae;
	ae.addVertex("Art", 0);
	ae.addVertex("Brt", 1, 0);
	ae.addVertex("Crt", 1, 0);
	ae.addVertex("Drt", 1, 2, 3, 0);
	ae.addVertex("Ert", 1, 2, 3, 4, 0);
	cout << ae;
	cout << "addEdge 2-3" << endl;
	ae.addEdge(2, 3);
	cout << ae;
	cout << "deleteEdge 2-4: " << endl;
	if (ae.checkEdge(2, 4))
	{
		ae.deleteEdge(2, 4);
	}
	cout << ae;
	cout << "deleteVertex Drt: " << endl;
	if (ae.checkVertex("Drt"))
	{
		ae.deleteVertex("Drt");
	}
	cout << ae;
	cout << "kol-vo vertex: " << ae.quantVertex() << endl;
	cout << "kol-vo edge: " << ae.quantEdge() << endl;
	cout << "powerVertex Crt: " << ae.powerVertex("Crt") << endl;
	cout << "empty: " << ae.empty() << endl;
	
	AdgList<string> ar = ae;
	cout << "ar: " << endl;
	cout << ar;
	cout << "ae: " << endl;
	cout << ae;
	cout << "ar == ae: " << (ar == ae) << endl;
	
	auto it = ae.ibegin("Art");
	
	cout << (*it).first << " " << (*it).second << endl;
	++it;
	cout << (*it).first << " " << (*it).second << endl;
	cout << "delete for iterator: " << endl;

	ae.eraseEdge(it);
	cout << ae;
	cout << "clear:" << endl;
	ae.clear();
	cout << "empty: " << ae.empty() << endl;
	cout << ae;
	system("pause");
	return 0;
}