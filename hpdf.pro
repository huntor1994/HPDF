TEMPLATE = subdirs

SUBDIRS += \ 
    hpdf-lib \
    hpdf-tests \
    hpdf-ui

!build_pass:message(hpdf project dir: $${PWD})
