import os

env = Environment()

src_dir = 'src'
inc_dir = 'include'

src_folders = []

sources = []
for tpl in os.walk(src_dir):
    directory = tpl[0]
    src_folders.append(directory)
for folder in src_folders:
    sources.extend(Glob(folder+"/*.cpp"))

env.Append(CPPPATH=inc_dir)
env.Append(LINKFLAGS=["-pthread"])
env.Append(CXXFLAGS=["-std=c++17"])

env.Program(target='TreasureGame',source=sources)