
import hou
import pdg
import string


def eval_pdg(attrname):
    if not (active := pdg.workItem()):
        return None
    if not (attr := active.attrib(attrname)):
        return None
    return attr.value()


# TODO: add support for passing in an index to check
def expand_str(val: str, encode:bool=False):
    result = []
    for head, field, spec, conversion in string.Formatter().parse(val):
        result.append(head)
        if field:
            pdgval = eval_pdg(field)
            pdgvals = str(pdgval) if pdgval else None
            result.append(pdgvals or hou.contextOption(field) or '')
    return ''.join(result)

