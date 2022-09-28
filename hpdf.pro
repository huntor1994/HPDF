TEMPLATE = subdirs

SUBDIRS += \
#    hpdf-tests \
    hpdf-lib \
    hpdf-ui

!build_pass:message(hpdf project dir: $${PWD})
