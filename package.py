name = "houdini_multishot"

version = "0.0.1"

authors = ["hundredsofbears",]

requires = ["houdini"]

def commands():
    env.PYTHONPATH.append("{root}/python")
    if "HOUDINI_DSO_PATH" not in env.keys():
        env.HOUDINI_DSO_PATH.set("&")
    env.HOUDINI_DSO_PATH.prepend("{root}/dso")
    if "HOUDINI_OTLSCAN_PATH" not in env.keys():
        env.HOUDINI_OTLSCAN_PATH.set("&")
    env.HOUDINI_OTLSCAN_PATH.prepend("{root}/otls")

uuid = "houdini_multishot"

