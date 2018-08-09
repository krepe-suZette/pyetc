from distutils.core import setup, Extension, DEBUG

sfc_module = Extension('etcpy', sources=['etcpy.c', 'etc.c'], language="c")

setup(name='etcpy',
      version='0.1.1',
      description='Decode ETC image data',
      author="Krepe-suZette",
      python_requires=">=3.5",
      ext_modules=[sfc_module]
      )
