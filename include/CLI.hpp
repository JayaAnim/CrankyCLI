#ifndef CLI_HPP
#define CLI_HPP


class CLI {
	public:
		virtual bool run(int next_pos, int argc, char* argv[]) = 0;
		virtual CLI* getLastNode() = 0;
		virtual CLI* navigateBack() = 0;
		// Default function for validate
		static bool defaultValidate(int next_pos, char* argv[]) ;
		// Default function for execute
		static void defaultExecute();
		// Default function for help
		static void defaultHelp();
		// Default function for error
		static bool defaultError(int code, int next_pos, char* argv[]);
		CLI* prev_node = nullptr;
		bool executable = false;
		bool (*validate)(int next_pos, char* argv[]) = &defaultValidate;
		void (*execute)() = &defaultExecute;
		void (*help)() = &defaultHelp;
		bool (*error)(int code, int next_pos, char* argv[]) = &defaultError;
};

#endif

