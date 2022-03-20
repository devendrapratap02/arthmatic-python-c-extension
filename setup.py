from distutils.core import setup, Extension

setup(
    name = 'arthmatic',
    version = '1.2',
    ext_modules = [
        Extension('arthmatic', ['arthmatic.c'])
    ]
)
