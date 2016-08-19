#include <iostream>
#include <string>

using namespace std;

int main() {
	string buf, result = "";
	getline(cin, buf);

	if (buf[0] < 'a' || buf[0] == '_' || buf[buf.size() - 1] == '_') {
		cout << "Error!";
		return 1;
	}

	for (unsigned int i = 0; i < buf.size(); i++) {
		if (buf[i] == '_') {
			for (; i < buf.size(); i++) {
				if (buf[i] == '_') {
					i++;
					if (buf[i] >= 'a') {
						result.push_back(buf[i] - 32);
					} else {
						cout << "Error!";
						return 1;
					}
				} else if (buf[i] < 'a') {
					cout << "Error!";
					return 1;
				} else {
					result.push_back(buf[i]);
				}
			}
		} else if (buf[i] < 'a') {
			for (; i < buf.size(); i++) {
				if (buf[i] < 'a') {
					result.push_back('_');
					result.push_back(buf[i] + 32);
				} else if (buf[i] == '_') {
					cout << "Error!";
					return 1;
				} else {
					result.push_back(buf[i]);
				}
			}
		} else {
			result.push_back(buf[i]);
		}
	}

	std::cout << result;
}