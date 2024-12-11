#import "PKParser.h"

enum {
    OBJCPARSER_TOKEN_KIND_CONST = 14,
    OBJCPARSER_TOKEN_KIND_IBOUTLET = 15,
    OBJCPARSER_TOKEN_KIND_CLASS = 16,
    OBJCPARSER_TOKEN_KIND_OPEN_CURLY = 17,
    OBJCPARSER_TOKEN_KIND_CLOSE_CURLY = 18,
    OBJCPARSER_TOKEN_KIND_ASSIGN = 19,
    OBJCPARSER_TOKEN_KIND_GETTER = 20,
    OBJCPARSER_TOKEN_KIND_P = 21,
    OBJCPARSER_TOKEN_KIND_WEAK = 22,
    OBJCPARSER_TOKEN_KIND_EXTERN = 23,
    OBJCPARSER_TOKEN_KIND_METHODCOLON = 24,
    OBJCPARSER_TOKEN_KIND_ENUM = 25,
    OBJCPARSER_TOKEN_KIND_SEMI = 26,
    OBJCPARSER_TOKEN_KIND_END = 27,
    OBJCPARSER_TOKEN_KIND_LT_SYM = 28,
    OBJCPARSER_TOKEN_KIND_READONLY = 29,
    OBJCPARSER_TOKEN_KIND_ATOMICITY = 30,
    OBJCPARSER_TOKEN_KIND_EQUALS = 31,
    OBJCPARSER_TOKEN_KIND_SETTER = 32,
    OBJCPARSER_TOKEN_KIND_GT_SYM = 33,
    OBJCPARSER_TOKEN_KIND_MIS_MANY_TO_MANY = 34,
    OBJCPARSER_TOKEN_KIND_PROPERTY = 35,
    OBJCPARSER_TOKEN_KIND_STATIC = 36,
    OBJCPARSER_TOKEN_KIND_OPEN_PAREN = 37,
    OBJCPARSER_TOKEN_KIND_CLOSE_PAREN = 38,
    OBJCPARSER_TOKEN_KIND_MIS_PROPERTY = 39,
    OBJCPARSER_TOKEN_KIND_MIS_ONE_TO_ONE = 40,
    OBJCPARSER_TOKEN_KIND_STAR = 41,
    OBJCPARSER_TOKEN_KIND_STRONG = 42,
    OBJCPARSER_TOKEN_KIND_AT = 43,
    OBJCPARSER_TOKEN_KIND_PLUS = 44,
    OBJCPARSER_TOKEN_KIND_OPEN_BRACKET = 45,
    OBJCPARSER_TOKEN_KIND_COMMA = 46,
    OBJCPARSER_TOKEN_KIND_COPY = 47,
    OBJCPARSER_TOKEN_KIND_RETAIN = 48,
    OBJCPARSER_TOKEN_KIND_MIS_ONE_TO_MANY = 49,
    OBJCPARSER_TOKEN_KIND_CLOSE_BRACKET = 50,
    OBJCPARSER_TOKEN_KIND_MINUS = 51,
    OBJCPARSER_TOKEN_KIND_STRUCT = 52,
    OBJCPARSER_TOKEN_KIND_CARET = 53,
    OBJCPARSER_TOKEN_KIND_TYPEDEF = 54,
    OBJCPARSER_TOKEN_KIND_UNION = 55,
    OBJCPARSER_TOKEN_KIND_READWRITE = 56,
    OBJCPARSER_TOKEN_KIND_INTERFACE = 57,
    OBJCPARSER_TOKEN_KIND_PROTOCOL = 58,
};

@interface ObjCParser : PKParser

@end
