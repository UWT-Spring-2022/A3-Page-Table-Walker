cmd_/home/virtuoso/Applications/OS/A3/procReport/Module.symvers := sed 's/ko$$/o/' /home/virtuoso/Applications/OS/A3/procReport/modules.order | scripts/mod/modpost -m    -o /home/virtuoso/Applications/OS/A3/procReport/Module.symvers -e -i Module.symvers   -T -