#pragma once

#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
#include <vector>

#include "../include/token.h"

namespace ceres {
	class Lexer {
	public:
		Lexer();

		inline bool eof() { return pos >= src.length(); }
		inline void advance() { 
			pos++;
		}

		inline void push_token(Token t) {
			tokens.push_back(t);
		}

		inline char peek() {
			if (eof()) return '\0';
			return src[pos];
		}

		std::vector<Token> scan(const std::string& s);
		void number();
		void string(char starting);
		void identifier();

	private:
		size_t pos;
		std::string src;
		std::vector<std::string> reserved_kw;
		std::vector<std::string> reserved_types;

		std::vector<Token> tokens;
	};
};
