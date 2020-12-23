export CXXFLAGS=-Wno-int-in-bool-context

export THREAD_COUNT=8
export PYTHON_PATH=/usr/local/Cellar/python@3.9/3.9.1/bin/python3
export PYTHON_LIB=/usr/local/Cellar/python@3.9/3.9.1/Frameworks/Python.framework/Versions/3.9/lib
export PYTHON_INCLUDE=/usr/local/Cellar/python@3.9/3.9.1/Frameworks/Python.framework/Versions/3.9/include

"$PYTHON_PATH" makepanda/makepanda.py --everything --wheel --threads $THREAD_COUNT --python-incdir "$PYTHON_INCLUDE" --python-libdir "$PYTHON_LIB"
