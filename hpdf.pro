TEMPLATE = subdirs

SUBDIRS += \
#    hpdf-tests \
    hpdf-lib \
    hpdf-tests \
    hpdf-ui

!build_pass:message(hpdf project dir: $${PWD})
