import os
from setuptools import setup, Extension

module = Extension('spam', sources=['spammodule.cpp'], language='c++')

setup(name='spam', ext_modules = [module])
