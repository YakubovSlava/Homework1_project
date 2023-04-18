import os
import subprocess


def check_output(cond):
    if not cond:
        raise RuntimeError("Check not passed")
    else:
        print('Passed')

def json_integration_test(command, input_row):
    print('Run command:"', command, '" with row ', input_row)
    p = subprocess.run([command], stdout=subprocess.PIPE, input=input_row, encoding='ascii')
    return p.stdout


simple_tests = [
    ['{a:123,b:"123"}', '123 - INT\n"123" - STRING\n'],
    ['{a:123,b:"123"}', '123 - INT\n"123" - STRING\n'],
    ['{a:123,b:"123",c:[234, 345]}', '123 - INT\n"123" - STRING\n[234,345] - ARRAY\n234 - INT\n345 - INT\n'],
    ['{a:123,b:"123",c:[234, 345, {test: 123}]}', '123 - INT\n"123" - STRING\n[234,345,{test:123}] - ARRAY\n234 - INT\n345 - INT\n{test:123} - DICT\n123 - INT\n'],
]


super_test = """{"glossary":{"title":"exampleglossary", "check_int": 123,"GlossDiv":{"title":"S","GlossList":\
{"GlossEntry":{"ID":"SGML","SortAs":"SGML","GlossTerm":"StandardGeneralizedMarkupLanguage","Acronym":"SGML","\
Abbrev":"ISO8879:1986","GlossDef":{"para":"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.",\
"GlossSeeAlso":["GML","XML", 123]},"GlossSee":"markup"}}}}}"""

super_test_result = """{"title":"exampleglossary","check_int":123,"GlossDiv":{"title":"S","GlossList":{"GlossEntry":{"ID":"SGML","SortAs":"SGML","GlossTerm":"StandardGeneralizedMarkupLanguage","Acronym":"SGML","Abbrev":"ISO8879:1986","GlossDef":{"para":"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.","GlossSeeAlso":["GML","XML",123]},"GlossSee":"markup"}}}} - DICT
"exampleglossary" - STRING
123 - INT
{"title":"S","GlossList":{"GlossEntry":{"ID":"SGML","SortAs":"SGML","GlossTerm":"StandardGeneralizedMarkupLanguage","Acronym":"SGML","Abbrev":"ISO8879:1986","GlossDef":{"para":"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.","GlossSeeAlso":["GML","XML",123]},"GlossSee":"markup"}}} - DICT
"S" - STRING
{"GlossEntry":{"ID":"SGML","SortAs":"SGML","GlossTerm":"StandardGeneralizedMarkupLanguage","Acronym":"SGML","Abbrev":"ISO8879:1986","GlossDef":{"para":"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.","GlossSeeAlso":["GML","XML",123]},"GlossSee":"markup"}} - DICT
{"ID":"SGML","SortAs":"SGML","GlossTerm":"StandardGeneralizedMarkupLanguage","Acronym":"SGML","Abbrev":"ISO8879:1986","GlossDef":{"para":"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.","GlossSeeAlso":["GML","XML",123]},"GlossSee":"markup"} - DICT
"SGML" - STRING
"SGML" - STRING
"StandardGeneralizedMarkupLanguage" - STRING
"SGML" - STRING
"ISO8879:1986" - STRING
{"para":"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.","GlossSeeAlso":["GML","XML",123]} - DICT
"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook." - STRING
["GML","XML",123] - ARRAY
"GML" - STRING
"XML" - STRING
123 - INT
"markup" - STRING
"""

check_output(json_integration_test('../../bin/main_parser', '{a: 123}') == '123 - INT\n')
for a, b in simple_tests:
    check_output(json_integration_test('../../bin/main_parser', a) == b)
check_output(json_integration_test('../../bin/main_parser', super_test) == super_test_result)
