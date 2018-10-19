from distutils.core import setup, Extension, DEBUG

sfc_module = Extension('pyetc', sources=['pyetc.c', 'etc.c'], language="c")

setup(name='pyetc',
      version='0.2.0',
      description='Decode ETC image data',
      author="Krepe-suZette",
      python_requires=">=3.5",
      ext_modules=[sfc_module]
      )
