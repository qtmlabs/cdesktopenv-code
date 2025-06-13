FILES = dtlogin.service

help:
	@echo This directory contains systemd service definitions and configuration files for CDE.
	@echo
	@echo Run \"sudo make install\" to install the systemd configuration files.
	@echo Run \"sudo make uninstall\" to uninstall the systemd configuration files.

install:
	for file in $(FILES) ; do \
		install -m 0644 -D "$${file}" "/usr/local/lib/systemd/system/$${file}" ; \
	done
	command -v systemctl >/dev/null && systemctl daemon-reload

uninstall:
	for file in $(FILES) ; do \
		rm -f "/usr/local/lib/systemd/system/$${file}" ; \
	done
	command -v systemctl >/dev/null && systemctl daemon-reload
