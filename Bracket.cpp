#include "Bracket.h"

Bracket::Bracket(bool isLeft) {
    setTokenType(tokenType::BRACKET);
    isLeftBracket = isLeft;
}

bool Bracket::isOpen() const {
    return isLeftBracket;
}
