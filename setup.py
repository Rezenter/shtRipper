import setuptools
import codecs

with codecs.open('README.md', encoding='utf-8') as fh:
    long_description = fh.read()

setuptools.setup(
    name="shtRipper",
    version="0.4",
    author="Rezenter",
    author_email="",
    description="Parser of .sht files.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://gitlab.spectraltech.ru/Rezenter/shtRipper",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
    install_requires=['matplotlib', 'urllib3', 'pysmb'],
    entry_points={
        'console_scripts': [
            'cursive = cursive.tools.cmd:cursive_command',
        ],
    },
)
