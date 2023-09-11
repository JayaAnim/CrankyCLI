#ifndef ARGUMENTNODE_HPP
#define ARGUMENTNODE_HPP
#include <vector>
#include "CLI.hpp"
#include "Option.hpp"

class ArgumentNode : public CLI {
	public: 
		ArgumentNode(CLI* node, const char** name, bool executable);
		bool run(int next_pos, int argc, char* argv[]) override;
		CLI* getLastNode() override;
		CLI* navigateBack() override;
		bool addArgNode(char** const name); //returns false if it failed (because next_cmd exists)
		bool addCmdNode(char** const name); //returns false if it failed (because next_arg exists
		void addFlag(const char** name, bool value);
		bool addOption(const char** name, BaseOption* value); //returns false if T value causes issue
	private:
		const char** name; //arg name to match to compare arg with argv 
		CommandNode* next_cmd; //cmd object, which is nullptr unless end of args is reached and next is a cmd (cmd cannot exist if arg is not nullptr)
		ArguementNode* next_arg; //arg object, which points to next object if there is any (arg cannot exist if cmd is not nullptr)
		vector<string, bool> flags; //vector of possible flags, by default they are false
		vector<BaseOption*> options; //vector of possible options
};

#endif
