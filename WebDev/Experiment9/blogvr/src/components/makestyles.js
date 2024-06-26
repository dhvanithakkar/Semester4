import { useTheme } from '@mui/material/styles';
//WARNING: tss-react require TypeScript v4.4 or newer. If you can't update use:
//import { createMakeAndWithStyles } from "tss-react/compat";
import { createMakeAndWithStyles } from 'tss-react';

export const { makeStyles, withtyles } = createMakeAndWithStyles({
  useTheme,
  /*
    OR, if you have extended the default mui theme adding your own custom properties:
    Let's assume the myTheme object that you provide to the <ThemeProvider /> is of
    type MyTheme then you'll write:
    */
  //"useTheme": useTheme as (()=> MyTheme)
});

