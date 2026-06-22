
import hou
import string


def expand_str(val: str, encode:bool=False):
    result = []
    formatter = string.Formatter()
    for head, field, spec, conversion in formatter.parse(val):
        result.append(head)
        result.append(hou.contextOption(field) or '')
    return ''.join(result)

