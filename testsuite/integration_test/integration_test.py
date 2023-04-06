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
    ['{a:123,b:"123",c:[234,345]}', '123 - INT\n"123" - STRING\n[234,345] - ARRAY\n234 - INT\n345 - INT\n']]



check_output(json_integration_test('../../bin/main_parser', '{a:123}') == '123 - INT\n')
for a, b in simple_tests:
    check_output(json_integration_test('../../bin/main_parser', a) == b)
