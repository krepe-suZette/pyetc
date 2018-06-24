# etcpy

Decoding ETC1 image data to RGBA string for Python

## Install
```bash
pip install .
```

## Usage
```python
import cv2
import etcpy

res = etcpy.decode_etc1(rawdata, width, height)
```

## Original source
`etc.h`, `etc.py` : [Ishotihadus/mikunyan](https://github.com/Ishotihadus/mikunyan/tree/master/ext/decoders/native)