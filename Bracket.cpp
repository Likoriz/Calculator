#include "Bracket.h"

Bracket::Bracket(bool isLeft)
{
	setTokenType(tokenType::BRACKET);
	isLeftBracket=isLeft;
}
