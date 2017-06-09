del _build\* /q
del _docs\* /q

protogen.exe drone_can_protocol.xml _build -docs _docs --no-markdown
