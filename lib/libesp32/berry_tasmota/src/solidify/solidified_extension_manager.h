/* Solidification of extension_manager.h */
/********************************************************************\
* Generated code, don't edit                                         *
\********************************************************************/
#include "be_constobj.h"
extern const bclass be_class_Extension_manager;
// compact class 'Extension_manager' ktab size: 171, total: 302 (saved 1048 bytes)
static const bvalue be_ktab_class_Extension_manager[171] = {
  /* K0   */  be_nested_str(webserver),
  /* K1   */  be_nested_str(check_privileged_access),
  /* K2   */  be_nested_str(has_arg),
  /* K3   */  be_nested_str(store),
  /* K4   */  be_nested_str(page_extensions_store),
  /* K5   */  be_nested_str(page_extensions_mgr),
  /* K6   */  be_const_class(be_class_Extension_manager),
  /* K7   */  be_nested_str(string),
  /* K8   */  be_nested_str(tasmota),
  /* K9   */  be_nested_str(cmd),
  /* K10  */  be_nested_str(_OtaUrl),
  /* K11  */  be_nested_str(OtaUrl),
  /* K12  */  be_nested_str(split),
  /* K13  */  be_nested_str(_X2F),
  /* K14  */  be_nested_str(_X25s_X2F_X2F_X25s_X2Fextensions_X2F),
  /* K15  */  be_const_int(0),
  /* K16  */  be_const_int(2),
  /* K17  */  be_nested_str(tapp_name),
  /* K18  */  be_nested_str(list_installed_ext),
  /* K19  */  be_nested_str(find),
  /* K20  */  be_nested_str(path),
  /* K21  */  be_nested_str(run_stop_ext),
  /* K22  */  be_nested_str(remove),
  /* K23  */  be_nested_str(on),
  /* K24  */  be_nested_str(_X2Fext),
  /* K25  */  be_nested_str(HTTP_GET),
  /* K26  */  be_nested_str(HTTP_POST),
  /* K27  */  be_nested_str(exists),
  /* K28  */  be_nested_str(isdir),
  /* K29  */  be_nested_str(mkdir),
  /* K30  */  be_nested_str(cannot_X20create_X20folder_X20_X27_X25s_X27),
  /* K31  */  be_nested_str(io_error),
  /* K32  */  be_const_int(1),
  /* K33  */  be_nested_str(_X23),
  /* K34  */  be_nested_str(_),
  /* K35  */  be_nested_str(_X2Etapp),
  /* K36  */  be_nested_str(listdir),
  /* K37  */  be_nested_str(EXT_FOLDER),
  /* K38  */  be_nested_str(endswith),
  /* K39  */  be_nested_str(_X2Etapp_),
  /* K40  */  be_nested_str(push),
  /* K41  */  be_nested_str(stop_iteration),
  /* K42  */  be_nested_str(add_driver),
  /* K43  */  be_nested_str(json),
  /* K44  */  be_nested_str(load),
  /* K45  */  be_nested_str(log),
  /* K46  */  be_nested_str(EXT_X3A_X20unable_X20to_X20parse_X20manifest_X20line_X20_X27_X25s_X27),
  /* K47  */  be_const_int(3),
  /* K48  */  be_nested_str(contains),
  /* K49  */  be_nested_str(name),
  /* K50  */  be_nested_str(file),
  /* K51  */  be_nested_str(version),
  /* K52  */  be_nested_str(EXT_X3A_X20manifest_X20is_X20missing_X20_X27name_X2Ffile_X2Fversion_X27_X20in_X20map_X20_X27_X25s_X27),
  /* K53  */  be_nested_str(description),
  /* K54  */  be_nested_str(_X5Bno_X20description_X5D),
  /* K55  */  be_nested_str(author),
  /* K56  */  be_nested_str(),
  /* K57  */  be_nested_str(content_send),
  /* K58  */  be_nested_str(_X3Cp_X3E_X3C_X2Fp_X3E_X3Cform_X20id_X3Dbut_part_mgr_X20style_X3D_X27display_X3A_X20block_X3B_X27_X20action_X3D_X27ext_X27_X20method_X3D_X27get_X27_X3E_X3Cbutton_X3EExtension_X20Manager_X3C_X2Fbutton_X3E_X3C_X2Fform_X3E_X3Cp_X3E_X3C_X2Fp_X3E),
  /* K59  */  be_nested_str(sortedmap),
  /* K60  */  be_nested_str(list_extensions),
  /* K61  */  be_nested_str(read_extension_manifest),
  /* K62  */  be_nested_str(EXT_X3A_X20unable_X20to_X20read_X20details_X20from_X20_X27_X25s_X27),
  /* K63  */  be_nested_str(v_X25s_X2E_X25s_X2E_X25s_X2E_X25s),
  /* K64  */  be_nested_str(_X25s_X25s_X25s),
  /* K65  */  be_nested_str(EXT_REPO),
  /* K66  */  be_nested_str(EXT_REPO_FOLDER),
  /* K67  */  be_nested_str(ext_repo_local),
  /* K68  */  be_nested_str(check_or_create_dir),
  /* K69  */  be_nested_str(_X25s_X25s),
  /* K70  */  be_nested_str(webclient),
  /* K71  */  be_nested_str(EXT_X3A_X20installing_X20from_X20_X27_X25s_X27),
  /* K72  */  be_nested_str(begin),
  /* K73  */  be_nested_str(GET),
  /* K74  */  be_nested_str(close),
  /* K75  */  be_nested_str(EXT_X3A_X20return_code_X3D_X25s),
  /* K76  */  be_nested_str(write_file),
  /* K77  */  be_nested_str(EXT_X3A_X20successfully_X20installed_X20_X27_X25s_X27_X20_X25s_X20bytes),
  /* K78  */  be_nested_str(could_X20not_X20download_X20into_X20_X27_X25s_X27_X20ret_X3D_X25s),
  /* K79  */  be_nested_str(EXT_X3A_X20exception_X20_X27_X25s_X27_X20_X2D_X20_X27_X25s_X27),
  /* K80  */  be_nested_str(arg_name),
  /* K81  */  be_const_int(2147483647),
  /* K82  */  be_nested_str(r),
  /* K83  */  be_nested_str(s),
  /* K84  */  be_nested_str(a),
  /* K85  */  be_nested_str(A),
  /* K86  */  be_nested_str(enable_disable_ext),
  /* K87  */  be_nested_str(d),
  /* K88  */  be_nested_str(delete_ext),
  /* K89  */  be_nested_str(u),
  /* K90  */  be_nested_str(install_from_store),
  /* K91  */  be_nested_str(i),
  /* K92  */  be_nested_str(I),
  /* K93  */  be_nested_str(EXT_X3A_X20wrong_X20action_X20_X27_X25s_X27),
  /* K94  */  be_nested_str(redirect),
  /* K95  */  be_nested_str(EXT_X3A_X20Exception_X3E_X20_X27_X25s_X27_X20_X2D_X20_X25s),
  /* K96  */  be_nested_str(content_start),
  /* K97  */  be_nested_str(Parameter_X20error),
  /* K98  */  be_nested_str(content_send_style),
  /* K99  */  be_nested_str(_X3Cp_X20style_X3D_X27width_X3A340px_X3B_X27_X3E_X3Cb_X3EException_X3A_X3C_X2Fb_X3E_X3Cbr_X3E_X27_X25s_X27_X3Cbr_X3E_X25s_X3C_X2Fp_X3E),
  /* K100 */  be_nested_str(html_escape),
  /* K101 */  be_nested_str(content_button),
  /* K102 */  be_nested_str(BUTTON_MANAGEMENT),
  /* K103 */  be_nested_str(content_stop),
  /* K104 */  be_nested_str(Extensions_X20Manager),
  /* K105 */  be_nested_str(_X3Cdiv_X20style_X3D_X27padding_X3A0px_X205px_X3Btext_X2Dalign_X3Acenter_X3B_X27_X3E_X3Ch3_X3E_X3Chr_X3EExtension_X20Manager_X3Chr_X3E_X3C_X2Fh3_X3E_X3C_X2Fdiv_X3E),
  /* K106 */  be_nested_str_long(_X3Cscript_X3Efunction_X20loadext_X28_X29_X20_X7Beb_X28_X27store_X27_X29_X2Edisabled_X3Dtrue_X3Bx_X3Dnew_X20XMLHttpRequest_X28_X29_X3Bx_X2Etimeout_X3D4000_X3Bx_X2Eonreadystatechange_X20_X3D_X20_X28_X29_X20_X3D_X3E_X20_X7Bif_X28x_X2EreadyState_X3D_X3D4_X29_X7Bif_X28x_X2Estatus_X3D_X3D200_X29_X7Beb_X28_X27inet_X27_X29_X2Estyle_X2Edisplay_X3D_X27none_X27_X3Beb_X28_X27store_X27_X29_X2EouterHTML_X3Dx_X2EresponseText_X3B_X7D_X7D_X7D_X3Bx_X2Eopen_X28_X27GET_X27_X2C_X27_X3Fstore_X3D_X27_X29_X3Bx_X2Esend_X28_X29_X3B_X7Dwindow_X2Eonload_X3Dfunction_X28_X29_X7Bloadext_X28_X29_X3B_X7D_X3Bfunction_X20toggleDesc_X28id_X29_X20_X7Bvar_X20desc_X20_X3D_X20document_X2EgetElementById_X28_X27desc_X2D_X27_X20_X2B_X20id_X29_X3Bvar_X20arrow_X20_X3D_X20document_X2EgetElementById_X28_X27arrow_X2D_X27_X20_X2B_X20id_X29_X3Bif_X20_X28desc_X2Estyle_X2Edisplay_X20_X3D_X3D_X3D_X20_X27none_X27_X20_X7C_X7C_X20desc_X2Estyle_X2Edisplay_X20_X3D_X3D_X3D_X20_X27_X27_X29_X20_X7Bdesc_X2Estyle_X2Edisplay_X20_X3D_X20_X27block_X27_X3Barrow_X2EinnerHTML_X20_X3D_X20_X27_XE2_X96_XBC_X27_X3B_X7D_X20else_X20_X7Bdesc_X2Estyle_X2Edisplay_X20_X3D_X20_X27none_X27_X3Barrow_X2EinnerHTML_X20_X3D_X20_X27_XE2_X96_XB6_X27_X3B_X7D_X7Dfunction_X20filterExtensions_X28query_X29_X20_X7Bvar_X20items_X20_X3D_X20document_X2EgetElementsByClassName_X28_X27ext_X2Dstore_X2Ditem_X27_X29_X3Bquery_X20_X3D_X20query_X2EtoLowerCase_X28_X29_X3Bfor_X20_X28var_X20i_X20_X3D_X200_X3B_X20i_X20_X3C_X20items_X2Elength_X3B_X20i_X2B_X2B_X29_X20_X7Bvar_X20name_X20_X3D_X20items_X5Bi_X5D_X2EgetElementsByClassName_X28_X27ext_X2Dname_X27_X29_X5B0_X5D_X2EtextContent_X2EtoLowerCase_X28_X29_X3Bvar_X20desc_X20_X3D_X20items_X5Bi_X5D_X2EgetElementsByClassName_X28_X27ext_X2Ddesc_X27_X29_X5B0_X5D_X2EtextContent_X2EtoLowerCase_X28_X29_X3Bif_X20_X28name_X2Eincludes_X28query_X29_X20_X7C_X7C_X20desc_X2Eincludes_X28query_X29_X29_X20_X7Bitems_X5Bi_X5D_X2Estyle_X2Edisplay_X20_X3D_X20_X27block_X27_X3B_X7D_X20else_X20_X7Bitems_X5Bi_X5D_X2Estyle_X2Edisplay_X20_X3D_X20_X27none_X27_X3B_X7D_X7D_X7D_X3C_X2Fscript_X3E),
  /* K107 */  be_nested_str_long(_X3Cfieldset_X20style_X3D_X27padding_X3A0_X205px_X3B_X27_X3E_X3Cstyle_X3E_X2Eext_X2Ditem_X7Bwidth_X3Amin_X2Dcontent_X3Bmin_X2Dwidth_X3A100_X25_X3B_X7D_X2Eext_X2Ditem_X20small_X7Bdisplay_X3Ablock_X3Bword_X2Dwrap_X3Abreak_X2Dword_X3Boverflow_X2Dwrap_X3Abreak_X2Dword_X3Bwhite_X2Dspace_X3Anormal_X3Bpadding_X2Dright_X3A5px_X3Bpadding_X2Dtop_X3A2px_X3B_X7D_X2Eext_X2Dcontrols_X7Bdisplay_X3Aflex_X3Bgap_X3A8px_X3Balign_X2Ditems_X3Acenter_X3Bmargin_X2Dtop_X3A4px_X3Bpadding_X3A0px_X7D_X2Ebtn_X2Dsmall_X7Bpadding_X3A0_X206px_X3Bline_X2Dheight_X3A1_X2E8rem_X3Bfont_X2Dsize_X3A0_X2E9rem_X3Bmin_X2Dwidth_X3Aauto_X3Bwidth_X3Aauto_X3Bflex_X2Dshrink_X3A0_X3B_X7Dform_X7Bpadding_X2Dtop_X3A0px_X3Bpadding_X2Dbottom_X3A0px_X3B_X7D_X2Erunning_X2Dindicator_X7Bdisplay_X3Ainline_X2Dblock_X3Bwidth_X3A8px_X3Bheight_X3A8px_X3Bborder_X2Dradius_X3A50_X25_X3Bmargin_X2Dright_X3A8px_X3Bbackground_X3Avar_X28_X2D_X2Dc_btnsvhvr_X29_X3Banimation_X3Apulse_X201_X2E5s_X20infinite_X3B_X7D_X40keyframes_X20pulse_X7B0_X25_X7Bopacity_X3A1_X3B_X7D50_X25_X7Bopacity_X3A0_X2E5_X3B_X7D100_X25_X7Bopacity_X3A1_X3B_X7D_X7D_X2Estore_X2Dheader_X7Bdisplay_X3Aflex_X3Bjustify_X2Dcontent_X3Aspace_X2Dbetween_X3Balign_X2Ditems_X3Acenter_X3Bmargin_X2Dbottom_X3A10px_X3B_X7D_X2Estore_X2Dstats_X7Bfont_X2Dsize_X3A0_X2E9em_X3Bcolor_X3Avar_X28_X2D_X2Dc_in_X29_X3B_X7D_X2Eext_X2Dstore_X2Ditem_X7Bbackground_X3Avar_X28_X2D_X2Dc_bg_X29_X3Bborder_X2Dradius_X3A0_X2E3em_X3Bmargin_X2Dbottom_X3A5px_X3Bpadding_X3A4px_X3B_X7D_X2Eext_X2Dheader_X7Bdisplay_X3Aflex_X3Bjustify_X2Dcontent_X3Aspace_X2Dbetween_X3Balign_X2Ditems_X3Acenter_X3Bcursor_X3Apointer_X3Buser_X2Dselect_X3Anone_X3Bpadding_X3A5px_X3B_X7D_X2Eext_X2Dtitle_X7Bdisplay_X3Aflex_X3Balign_X2Ditems_X3Acenter_X3Bgap_X3A6px_X3Bflex_X3A1_X3Bpadding_X3A0_X3B_X7D_X2Eext_X2Dname_X7Bfont_X2Dweight_X3Abold_X3B_X7D_X2Eext_X2Dversion_X7Bfont_X2Dsize_X3A0_X2E8em_X3B_X7D_X2Eext_X2Darrow_X7Bcolor_X3Avar_X28_X2D_X2Dc_in_X29_X3Bfont_X2Dsize_X3A0_X2E8em_X3B_X7D_X2Eext_X2Dbadges_X7Bpadding_X3A0_X3B_X7D_X2Eext_X2Ddetails_X7Bwidth_X3Amin_X2Dcontent_X3Bmin_X2Dwidth_X3A100_X25_X3Bpadding_X3A0_X3Bdisplay_X3Anone_X3B_X7D_X2Eext_X2Ddesc_X7Bcolor_X3Avar_X28_X2D_X2Dc_in_X29_X3Bfont_X2Dsize_X3A0_X2E8em_X3Bline_X2Dheight_X3A1_X2E4_X3Bdisplay_X3Ablock_X3Bword_X2Dwrap_X3Abreak_X2Dword_X3Boverflow_X2Dwrap_X3Abreak_X2Dword_X3Bwhite_X2Dspace_X3Anormal_X3Bpadding_X3A0_X205px_X3B_X7D_X2Eext_X2Dactions_X7Bdisplay_X3Aflex_X3Bgap_X3A8px_X3Bpadding_X3A5px_X3B_X7D_X2Ebtn_X2Daction_X7Bpadding_X3A0_X2012px_X3Bline_X2Dheight_X3A1_X2E8em_X3Bfont_X2Dsize_X3A0_X2E9em_X3Bflex_X3A1_X3B_X7D_X2Einstalled_X2Dbadge_X7Bborder_X2Dcolor_X3Avar_X28_X2D_X2Dc_btnhvr_X29_X3Bpadding_X3A0px_X204px_X3Bborder_X2Dradius_X3A4px_X3Bfont_X2Dsize_X3A0_X2E7em_X3Bborder_X2Dwidth_X3A2px_X3Bborder_X2Dstyle_X3Asolid_X3Bmargin_X2Dright_X3A3px_X3B_X7D_X2Eupdate_X2Dbadge_X7Bbackground_X3Avar_X28_X2D_X2Dc_btnhvr_X29_X3Bpadding_X3A2px_X206px_X3Bborder_X2Dradius_X3A4px_X3Bfont_X2Dsize_X3A0_X2E7em_X3Bmargin_X2Dright_X3A3px_X3Banimation_X3Apulse_X202s_X20infinite_X3B_X7D_X40keyframes_X20pulse_X7B0_X25_X7Bopacity_X3A1_X3B_X7D50_X25_X7Bopacity_X3A0_X2E7_X3B_X7D100_X25_X7Bopacity_X3A1_X3B_X7D_X7D_X3C_X2Fstyle_X3E_X3Clegend_X3E_X3Cb_X20title_X3D_X27Running_X20extensions_X27_X3E_X26nbsp_X3BInstalled_X20extensions_X3C_X2Fb_X3E_X3C_X2Flegend_X3E),
  /* K108 */  be_nested_str(list_extensions_in_fs),
  /* K109 */  be_nested_str(_X3Chr_X20style_X3D_X27margin_X3A2px_X200_X200_X200_X3B_X27_X3E),
  /* K110 */  be_nested_str(get_by_index),
  /* K111 */  be_nested_str(_ext),
  /* K112 */  be_nested_str(_X20_X3Cspan_X20class_X3D_X27running_X2Dindicator_X27_X20title_X3D_X27Running_X27_X3E_X3C_X2Fspan_X3E),
  /* K113 */  be_nested_str(autorun),
  /* K114 */  be_nested_str(style_X3D_X27background_X3Avar_X28_X2D_X2Dc_btnsvhvr_X29_X3B_X27),
  /* K115 */  be_nested_str(style_X3D_X27background_X3Avar_X28_X2D_X2Dc_btnoff_X29_X3B_X27),
  /* K116 */  be_nested_str(_X3Cdiv_X20class_X3D_X27ext_X2Ditem_X27_X3E),
  /* K117 */  be_nested_str(_X3Cspan_X20title_X3D_X27path_X3A_X20_X25s_X27_X3E_X3Cb_X3E_X25s_X3C_X2Fb_X3E_X25s_X3C_X2Fspan_X3E_X3Cbr_X3E),
  /* K118 */  be_nested_str(_X3Csmall_X3E_X25s_X3C_X2Fsmall_X3E),
  /* K119 */  be_nested_str(_X3Cdiv_X20class_X3D_X27ext_X2Dcontrols_X27_X20style_X3D_X27padding_X2Dtop_X3A0px_X3Bpadding_X2Dbottom_X3A0px_X3B_X27_X3E),
  /* K120 */  be_nested_str(_X3Cform_X20action_X3D_X27_X2Fext_X27_X20method_X3D_X27post_X27_X20class_X3D_X27ext_X2Dcontrols_X27_X3E),
  /* K121 */  be_nested_str(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Dsmall_X27_X20_X25s_X20name_X3D_X27_X25s_X25s_X27_X3E_X25s_X3C_X2Fbutton_X3E),
  /* K122 */  be_nested_str(Running),
  /* K123 */  be_nested_str(Stopped),
  /* K124 */  be_nested_str(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Dsmall_X27_X20_X25s_X20name_X3D_X27_X25s_X25s_X27_X3EAuto_X2Drun_X3A_X20_X25s_X3C_X2Fbutton_X3E),
  /* K125 */  be_nested_str(ON),
  /* K126 */  be_nested_str(OFF),
  /* K127 */  be_nested_str(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Dsmall_X20bred_X27_X20name_X3D_X27d_X25s_X27_X20onclick_X3D_X27return_X20confirm_X28_X22Confirm_X20deletion_X20of_X20_X25s_X2Etapp_X22_X29_X27_X3EUninstall_X3C_X2Fbutton_X3E),
  /* K128 */  be_nested_str(_X3C_X2Fform_X3E_X3C_X2Fdiv_X3E_X3C_X2Fdiv_X3E),
  /* K129 */  be_nested_str(_X3Cdiv_X3E_X3Csmall_X3E_X3Ci_X3ENo_X20installed_X20extension_X2E_X3C_X2Fi_X3E_X3C_X2Fsmall_X3E_X3C_X2Fp_X3E),
  /* K130 */  be_nested_str(_X3Cp_X3E_X3C_X2Fp_X3E_X3C_X2Ffieldset_X3E_X3Cp_X3E_X3C_X2Fp_X3E),
  /* K131 */  be_nested_str(_X3Cdiv_X20style_X3D_X27padding_X3A0px_X205px_X3Btext_X2Dalign_X3Acenter_X3B_X27_X3E_X3Ch3_X3E_X3Chr_X3EOnline_X20Store_X3Chr_X20style_X3D_X27margin_X2Dbottom_X3A0_X3B_X27_X3E_X3Cspan_X20id_X3D_X27inet_X27_X20style_X3D_X27font_X2Dsize_X3Asmall_X3Bfont_X2Dweight_X3Anormal_X3B_X27_X27_X3E_X26nbsp_X3B_X28This_X20feature_X20requires_X20an_X20internet_X20connection_X29_X3C_X2Fspan_X3E_X3C_X2Fh3_X3E_X3C_X2Fdiv_X3E),
  /* K132 */  be_nested_str(_X3Cb_X20id_X3D_X27store_X27_X3E_X5B_X20_X3Cspan_X20style_X3D_X27color_X3Avar_X28_X2D_X2Dc_btnsv_X29_X3B_X27_X3ELoading_X20from_X20Store_X2E_X2E_X2E_X3C_X2Fspan_X3E_X20_X5D_X3C_X2Fb_X3E),
  /* K133 */  be_nested_str(arch),
  /* K134 */  be_nested_str(0x_X2508X),
  /* K135 */  be_nested_str(_X25s_X25s_X3Fa_X3D_X25s_X26v_X3D_X25s),
  /* K136 */  be_nested_str(EXT_REPO_MANIFEST),
  /* K137 */  be_nested_str(EXT_X3A_X20fetching_X20extensions_X20manifest_X20_X27_X25s_X27),
  /* K138 */  be_nested_str(EXT_X3A_X20error_X20fetching_X20manifest_X20_X25s),
  /* K139 */  be_nested_str(Error_X20fetching_X20manifest_X20code_X3D_X25s),
  /* K140 */  be_nested_str(webclient_error),
  /* K141 */  be_nested_str(get_string),
  /* K142 */  be_nested_str(rename),
  /* K143 */  be_nested_str(unload_extension),
  /* K144 */  be_nested_str(content_open),
  /* K145 */  be_nested_str(text_X2Fhtml),
  /* K146 */  be_nested_str(load_manifest),
  /* K147 */  be_nested_str(_X3Cb_X20id_X3D_X27store_X27_X3E_X5B_X20_X3Cspan_X20style_X3D_X27color_X3Avar_X28_X2D_X2Dc_btnrst_X29_X3B_X27_X3EError_X20loading_X20manifest_X2E_X3C_X2Fspan_X3E_X20_X5D_X3C_X2Fb_X3E),
  /* K148 */  be_nested_str(_X3Cp_X3E_X3Csmall_X3E_X25s_X3C_X2Fsmall_X3E_X3C_X2Fp_X3E),
  /* K149 */  be_nested_str(content_close),
  /* K150 */  be_nested_str(count),
  /* K151 */  be_nested_str(_X22name_X22_X3A),
  /* K152 */  be_nested_str(_X3Cfieldset_X20id_X3D_X27store_X27_X3E),
  /* K153 */  be_nested_str(_X3Cdiv_X20class_X3D_X27store_X2Dheader_X27_X3E_X3Cspan_X3EBrowse_X20Extensions_X3C_X2Fspan_X3E_X3Cspan_X20class_X3D_X27store_X2Dstats_X27_X3E_X25s_X20available_X3C_X2Fspan_X3E_X3C_X2Fdiv_X3E),
  /* K154 */  be_nested_str(_X3Cinput_X20type_X3D_X27text_X27_X20placeholder_X3D_X27Search_X20extensions_X2E_X2E_X2E_X27_X20onkeyup_X3D_X27filterExtensions_X28this_X2Evalue_X29_X27_X3E_X3Cp_X3E_X3C_X2Fp_X3E),
  /* K155 */  be_nested_str(_X0A),
  /* K156 */  be_nested_str(manifest_decode),
  /* K157 */  be_nested_str(version_string),
  /* K158 */  be_nested_str(replace),
  /* K159 */  be_nested_str(_X5Cn),
  /* K160 */  be_nested_str(_X3Cbr_X3E),
  /* K161 */  be_nested_str(_X3Cdiv_X20class_X3D_X27ext_X2Dstore_X2Ditem_X27_X3E_X3Cdiv_X20class_X3D_X27ext_X2Dheader_X27_X20onclick_X3D_X27toggleDesc_X28_X22_X25s_X22_X29_X27_X3E_X3Cdiv_X20class_X3D_X27ext_X2Dtitle_X27_X3E_X3Cspan_X20class_X3D_X27ext_X2Dname_X27_X3E_X25s_X3C_X2Fspan_X3E_X3Cspan_X20class_X3D_X27ext_X2Dversion_X27_X3E_X3Csmall_X3E_X25s_X3C_X2Fsmall_X3E_X3C_X2Fspan_X3E_X3C_X2Fdiv_X3E),
  /* K162 */  be_nested_str(_X3Cdiv_X20class_X3D_X27ext_X2Dbadges_X27_X3E_X3Cspan_X20class_X3D_X27update_X2Dbadge_X27_X3EUpgrade_X3C_X2Fspan_X3E_X3C_X2Fdiv_X3E),
  /* K163 */  be_nested_str(_X3Cdiv_X20class_X3D_X27ext_X2Dbadges_X27_X3E_X3Cspan_X20class_X3D_X27installed_X2Dbadge_X27_X3EInstalled_X3C_X2Fspan_X3E_X3C_X2Fdiv_X3E),
  /* K164 */  be_nested_str(_X3Cspan_X20id_X3D_X27arrow_X2D_X25s_X27_X20class_X3D_X27ext_X2Darrow_X27_X3E_XE2_X96_XB6_X3C_X2Fspan_X3E_X3C_X2Fdiv_X3E_X3Cdiv_X20id_X3D_X27desc_X2D_X25s_X27_X20class_X3D_X27ext_X2Ddetails_X27_X3E_X3Cdiv_X20class_X3D_X27ext_X2Ddesc_X27_X3E_X25s),
  /* K165 */  be_nested_str(_X3Cbr_X3E_X25s_X20_XE2_X86_X92_X20_X25s),
  /* K166 */  be_nested_str(_X3C_X2Fdiv_X3E_X3Cform_X20action_X3D_X27_X2Fext_X27_X20method_X3D_X27post_X27_X20class_X3D_X27ext_X2Dactions_X27_X3E_X3Cdiv_X20style_X3D_X27width_X3A30_X25_X27_X3E_X3C_X2Fdiv_X3E),
  /* K167 */  be_nested_str(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Daction_X27_X20name_X3D_X27u_X25s_X27_X20onclick_X3D_X27return_X20confirm_X28_X22Confirm_X20upgrade_X20of_X20_X25s_X22_X29_X27_X3EUpgrade_X3C_X2Fbutton_X3E),
  /* K168 */  be_nested_str(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Daction_X27_X20style_X3D_X27visibility_X3Ahidden_X3B_X27_X3E_X3C_X2Fbutton_X3E),
  /* K169 */  be_nested_str(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Daction_X20bred_X27_X20name_X3D_X27d_X25s_X27_X20onclick_X3D_X27return_X20confirm_X28_X22Confirm_X20deletion_X20of_X20_X25s_X22_X29_X27_X3EUninstall_X3C_X2Fbutton_X3E),
  /* K170 */  be_nested_str_long(_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Daction_X27_X20name_X3D_X27i_X25s_X27_X20onclick_X3D_X27return_X20confirm_X28_X22Confirm_X20installation_X20of_X20_X25s_X22_X29_X27_X3EInstall_X3C_X2Fbutton_X3E_X3Cbutton_X20type_X3D_X27submit_X27_X20class_X3D_X27btn_X2Daction_X20bgrn_X27_X20name_X3D_X27I_X25s_X27_X20onclick_X3D_X27return_X20confirm_X28_X22Confirm_X20installation_X20of_X20_X25s_X22_X29_X27_X3EInstall_X2BRun_X3C_X2Fbutton_X3E),
};


extern const bclass be_class_Extension_manager;

/********************************************************************
** Solidified function: page_extensions_mgr_dispatcher
********************************************************************/
be_local_closure(class_Extension_manager_page_extensions_mgr_dispatcher,   /* name */
  be_nested_proto(
    5,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_page_extensions_mgr_dispatcher,
    &be_const_str_solidified,
    ( &(const binstruction[18]) {  /* code */
      0xA4060000,  //  0000  IMPORT	R1	K0
      0x8C080301,  //  0001  GETMET	R2	R1	K1
      0x7C080200,  //  0002  CALL	R2	1
      0x740A0001,  //  0003  JMPT	R2	#0006
      0x4C080000,  //  0004  LDNIL	R2
      0x80040400,  //  0005  RET	1	R2
      0x8C080302,  //  0006  GETMET	R2	R1	K2
      0x58100003,  //  0007  LDCONST	R4	K3
      0x7C080400,  //  0008  CALL	R2	2
      0x780A0003,  //  0009  JMPF	R2	#000E
      0x8C080104,  //  000A  GETMET	R2	R0	K4
      0x7C080200,  //  000B  CALL	R2	1
      0x80040400,  //  000C  RET	1	R2
      0x70020002,  //  000D  JMP		#0011
      0x8C080105,  //  000E  GETMET	R2	R0	K5
      0x7C080200,  //  000F  CALL	R2	1
      0x80040400,  //  0010  RET	1	R2
      0x80000000,  //  0011  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: ext_repo_local
********************************************************************/
be_local_closure(class_Extension_manager_ext_repo_local,   /* name */
  be_nested_proto(
    8,                          /* nstack */
    0,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_ext_repo_local,
    &be_const_str_solidified,
    ( &(const binstruction[18]) {  /* code */
      0x58000006,  //  0000  LDCONST	R0	K6
      0xA4060E00,  //  0001  IMPORT	R1	K7
      0xB80A1000,  //  0002  GETNGBL	R2	K8
      0x8C080509,  //  0003  GETMET	R2	R2	K9
      0x5810000A,  //  0004  LDCONST	R4	K10
      0x50140200,  //  0005  LDBOOL	R5	1	0
      0x7C080600,  //  0006  CALL	R2	3
      0x9408050B,  //  0007  GETIDX	R2	R2	K11
      0x8C0C030C,  //  0008  GETMET	R3	R1	K12
      0x5C140400,  //  0009  MOVE	R5	R2
      0x5818000D,  //  000A  LDCONST	R6	K13
      0x7C0C0600,  //  000B  CALL	R3	3
      0x60100018,  //  000C  GETGBL	R4	G24
      0x5814000E,  //  000D  LDCONST	R5	K14
      0x9418070F,  //  000E  GETIDX	R6	R3	K15
      0x941C0710,  //  000F  GETIDX	R7	R3	K16
      0x7C100600,  //  0010  CALL	R4	3
      0x80040800,  //  0011  RET	1	R4
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: delete_ext
********************************************************************/
be_local_closure(class_Extension_manager_delete_ext,   /* name */
  be_nested_proto(
    8,                          /* nstack */
    1,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_delete_ext,
    &be_const_str_solidified,
    ( &(const binstruction[26]) {  /* code */
      0x58040006,  //  0000  LDCONST	R1	K6
      0x8C080311,  //  0001  GETMET	R2	R1	K17
      0x5C100000,  //  0002  MOVE	R4	R0
      0x7C080400,  //  0003  CALL	R2	2
      0x5C000400,  //  0004  MOVE	R0	R2
      0x8C080312,  //  0005  GETMET	R2	R1	K18
      0x7C080200,  //  0006  CALL	R2	1
      0x8C080513,  //  0007  GETMET	R2	R2	K19
      0x5C100000,  //  0008  MOVE	R4	R0
      0x7C080400,  //  0009  CALL	R2	2
      0x4C0C0000,  //  000A  LDNIL	R3
      0x200C0403,  //  000B  NE	R3	R2	R3
      0x780E0009,  //  000C  JMPF	R3	#0017
      0xA40E2800,  //  000D  IMPORT	R3	K20
      0x8C100315,  //  000E  GETMET	R4	R1	K21
      0x5C180000,  //  000F  MOVE	R6	R0
      0x501C0000,  //  0010  LDBOOL	R7	0	0
      0x7C100600,  //  0011  CALL	R4	3
      0x8C100716,  //  0012  GETMET	R4	R3	K22
      0x5C180400,  //  0013  MOVE	R6	R2
      0x7C100400,  //  0014  CALL	R4	2
      0x80040800,  //  0015  RET	1	R4
      0x70020001,  //  0016  JMP		#0019
      0x500C0000,  //  0017  LDBOOL	R3	0	0
      0x80040600,  //  0018  RET	1	R3
      0x80000000,  //  0019  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: web_add_handler
********************************************************************/
be_local_closure(class_Extension_manager_web_add_handler,   /* name */
  be_nested_proto(
    7,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    1,                          /* has sup protos */
    ( &(const struct bproto*[ 2]) {
      be_nested_proto(
        2,                          /* nstack */
        0,                          /* argc */
        0,                          /* varg */
        1,                          /* has upvals */
        ( &(const bupvaldesc[ 1]) {  /* upvals */
          be_local_const_upval(1, 0),
        }),
        0,                          /* has sup protos */
        NULL,                       /* no sub protos */
        1,                          /* has constants */
        ( &(const bvalue[ 1]) {     /* constants */
        /* K0   */  be_nested_str(page_extensions_mgr_dispatcher),
        }),
        &be_const_str__X3Clambda_X3E,
        &be_const_str_solidified,
        ( &(const binstruction[ 4]) {  /* code */
          0x68000000,  //  0000  GETUPV	R0	U0
          0x8C000100,  //  0001  GETMET	R0	R0	K0
          0x7C000200,  //  0002  CALL	R0	1
          0x80040000,  //  0003  RET	1	R0
        })
      ),
      be_nested_proto(
        2,                          /* nstack */
        0,                          /* argc */
        0,                          /* varg */
        1,                          /* has upvals */
        ( &(const bupvaldesc[ 1]) {  /* upvals */
          be_local_const_upval(1, 0),
        }),
        0,                          /* has sup protos */
        NULL,                       /* no sub protos */
        1,                          /* has constants */
        ( &(const bvalue[ 1]) {     /* constants */
        /* K0   */  be_nested_str(page_extensions_ctl),
        }),
        &be_const_str__X3Clambda_X3E,
        &be_const_str_solidified,
        ( &(const binstruction[ 4]) {  /* code */
          0x68000000,  //  0000  GETUPV	R0	U0
          0x8C000100,  //  0001  GETMET	R0	R0	K0
          0x7C000200,  //  0002  CALL	R0	1
          0x80040000,  //  0003  RET	1	R0
        })
      ),
    }),
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_web_add_handler,
    &be_const_str_solidified,
    ( &(const binstruction[13]) {  /* code */
      0xA4060000,  //  0000  IMPORT	R1	K0
      0x8C080317,  //  0001  GETMET	R2	R1	K23
      0x58100018,  //  0002  LDCONST	R4	K24
      0x84140000,  //  0003  CLOSURE	R5	P0
      0x88180319,  //  0004  GETMBR	R6	R1	K25
      0x7C080800,  //  0005  CALL	R2	4
      0x8C080317,  //  0006  GETMET	R2	R1	K23
      0x58100018,  //  0007  LDCONST	R4	K24
      0x84140001,  //  0008  CLOSURE	R5	P1
      0x8818031A,  //  0009  GETMBR	R6	R1	K26
      0x7C080800,  //  000A  CALL	R2	4
      0xA0000000,  //  000B  CLOSE	R0
      0x80000000,  //  000C  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: check_or_create_dir
********************************************************************/
be_local_closure(class_Extension_manager_check_or_create_dir,   /* name */
  be_nested_proto(
    6,                          /* nstack */
    1,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_check_or_create_dir,
    &be_const_str_solidified,
    ( &(const binstruction[32]) {  /* code */
      0x58040006,  //  0000  LDCONST	R1	K6
      0xA40A2800,  //  0001  IMPORT	R2	K20
      0x8C0C051B,  //  0002  GETMET	R3	R2	K27
      0x5C140000,  //  0003  MOVE	R5	R0
      0x7C0C0400,  //  0004  CALL	R3	2
      0x780E0008,  //  0005  JMPF	R3	#000F
      0x8C0C051C,  //  0006  GETMET	R3	R2	K28
      0x5C140000,  //  0007  MOVE	R5	R0
      0x7C0C0400,  //  0008  CALL	R3	2
      0x780E0001,  //  0009  JMPF	R3	#000C
      0x80000600,  //  000A  RET	0
      0x70020002,  //  000B  JMP		#000F
      0x8C0C0516,  //  000C  GETMET	R3	R2	K22
      0x5C140000,  //  000D  MOVE	R5	R0
      0x7C0C0400,  //  000E  CALL	R3	2
      0x8C0C051D,  //  000F  GETMET	R3	R2	K29
      0x5C140000,  //  0010  MOVE	R5	R0
      0x7C0C0400,  //  0011  CALL	R3	2
      0x8C0C051B,  //  0012  GETMET	R3	R2	K27
      0x5C140000,  //  0013  MOVE	R5	R0
      0x7C0C0400,  //  0014  CALL	R3	2
      0x780E0003,  //  0015  JMPF	R3	#001A
      0x8C0C051C,  //  0016  GETMET	R3	R2	K28
      0x5C140000,  //  0017  MOVE	R5	R0
      0x7C0C0400,  //  0018  CALL	R3	2
      0x740E0004,  //  0019  JMPT	R3	#001F
      0x600C0018,  //  001A  GETGBL	R3	G24
      0x5810001E,  //  001B  LDCONST	R4	K30
      0x5C140000,  //  001C  MOVE	R5	R0
      0x7C0C0400,  //  001D  CALL	R3	2
      0xB0063E03,  //  001E  RAISE	1	K31	R3
      0x80000000,  //  001F  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: tapp_name
********************************************************************/
be_local_closure(class_Extension_manager_tapp_name,   /* name */
  be_nested_proto(
    12,                          /* nstack */
    1,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_tapp_name,
    &be_const_str_solidified,
    ( &(const binstruction[44]) {  /* code */
      0x58040006,  //  0000  LDCONST	R1	K6
      0xA40A0E00,  //  0001  IMPORT	R2	K7
      0x580C000F,  //  0002  LDCONST	R3	K15
      0x6010000C,  //  0003  GETGBL	R4	G12
      0x5C140000,  //  0004  MOVE	R5	R0
      0x7C100200,  //  0005  CALL	R4	1
      0x04100920,  //  0006  SUB	R4	R4	K32
      0x94140004,  //  0007  GETIDX	R5	R0	R4
      0x1C140B21,  //  0008  EQ	R5	R5	K33
      0x74160002,  //  0009  JMPT	R5	#000D
      0x94140004,  //  000A  GETIDX	R5	R0	R4
      0x1C140B22,  //  000B  EQ	R5	R5	K34
      0x78160000,  //  000C  JMPF	R5	#000E
      0x04100920,  //  000D  SUB	R4	R4	K32
      0x8C140513,  //  000E  GETMET	R5	R2	K19
      0x5C1C0000,  //  000F  MOVE	R7	R0
      0x58200023,  //  0010  LDCONST	R8	K35
      0x00240920,  //  0011  ADD	R9	R4	K32
      0x6028000C,  //  0012  GETGBL	R10	G12
      0x582C0023,  //  0013  LDCONST	R11	K35
      0x7C280200,  //  0014  CALL	R10	1
      0x0424120A,  //  0015  SUB	R9	R9	R10
      0x7C140800,  //  0016  CALL	R5	4
      0x28140B0F,  //  0017  GE	R5	R5	K15
      0x78160003,  //  0018  JMPF	R5	#001D
      0x6014000C,  //  0019  GETGBL	R5	G12
      0x58180023,  //  001A  LDCONST	R6	K35
      0x7C140200,  //  001B  CALL	R5	1
      0x04100805,  //  001C  SUB	R4	R4	R5
      0x4C140000,  //  001D  LDNIL	R5
      0x8C180513,  //  001E  GETMET	R6	R2	K19
      0x5C200000,  //  001F  MOVE	R8	R0
      0x5824000D,  //  0020  LDCONST	R9	K13
      0x5C280600,  //  0021  MOVE	R10	R3
      0x7C180800,  //  0022  CALL	R6	4
      0x5C140C00,  //  0023  MOVE	R5	R6
      0x28180D0F,  //  0024  GE	R6	R6	K15
      0x781A0002,  //  0025  JMPF	R6	#0029
      0x00180B20,  //  0026  ADD	R6	R5	K32
      0x5C0C0C00,  //  0027  MOVE	R3	R6
      0x7001FFF4,  //  0028  JMP		#001E
      0x40180604,  //  0029  CONNECT	R6	R3	R4
      0x94180006,  //  002A  GETIDX	R6	R0	R6
      0x80040C00,  //  002B  RET	1	R6
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: list_extensions
********************************************************************/
be_local_closure(class_Extension_manager_list_extensions,   /* name */
  be_nested_proto(
    10,                          /* nstack */
    0,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_list_extensions,
    &be_const_str_solidified,
    ( &(const binstruction[32]) {  /* code */
      0x58000006,  //  0000  LDCONST	R0	K6
      0xA4062800,  //  0001  IMPORT	R1	K20
      0xA40A0E00,  //  0002  IMPORT	R2	K7
      0x600C0012,  //  0003  GETGBL	R3	G18
      0x7C0C0000,  //  0004  CALL	R3	0
      0x60100010,  //  0005  GETGBL	R4	G16
      0x8C140324,  //  0006  GETMET	R5	R1	K36
      0x881C0125,  //  0007  GETMBR	R7	R0	K37
      0x7C140400,  //  0008  CALL	R5	2
      0x7C100200,  //  0009  CALL	R4	1
      0xA8020010,  //  000A  EXBLK	0	#001C
      0x5C140800,  //  000B  MOVE	R5	R4
      0x7C140000,  //  000C  CALL	R5	0
      0x8C180526,  //  000D  GETMET	R6	R2	K38
      0x5C200A00,  //  000E  MOVE	R8	R5
      0x58240023,  //  000F  LDCONST	R9	K35
      0x7C180600,  //  0010  CALL	R6	3
      0x741A0004,  //  0011  JMPT	R6	#0017
      0x8C180526,  //  0012  GETMET	R6	R2	K38
      0x5C200A00,  //  0013  MOVE	R8	R5
      0x58240027,  //  0014  LDCONST	R9	K39
      0x7C180600,  //  0015  CALL	R6	3
      0x781A0003,  //  0016  JMPF	R6	#001B
      0x8C180728,  //  0017  GETMET	R6	R3	K40
      0x88200125,  //  0018  GETMBR	R8	R0	K37
      0x00201005,  //  0019  ADD	R8	R8	R5
      0x7C180400,  //  001A  CALL	R6	2
      0x7001FFEE,  //  001B  JMP		#000B
      0x58100029,  //  001C  LDCONST	R4	K41
      0xAC100200,  //  001D  CATCH	R4	1	0
      0xB0080000,  //  001E  RAISE	2	R0	R0
      0x80040600,  //  001F  RET	1	R3
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: init
********************************************************************/
be_local_closure(class_Extension_manager_init,   /* name */
  be_nested_proto(
    4,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_init,
    &be_const_str_solidified,
    ( &(const binstruction[ 5]) {  /* code */
      0xB8061000,  //  0000  GETNGBL	R1	K8
      0x8C04032A,  //  0001  GETMET	R1	R1	K42
      0x5C0C0000,  //  0002  MOVE	R3	R0
      0x7C040400,  //  0003  CALL	R1	2
      0x80000000,  //  0004  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: manifest_decode
********************************************************************/
be_local_closure(class_Extension_manager_manifest_decode,   /* name */
  be_nested_proto(
    9,                          /* nstack */
    1,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_manifest_decode,
    &be_const_str_solidified,
    ( &(const binstruction[58]) {  /* code */
      0x58040006,  //  0000  LDCONST	R1	K6
      0xA40A5600,  //  0001  IMPORT	R2	K43
      0x8C0C052C,  //  0002  GETMET	R3	R2	K44
      0x5C140000,  //  0003  MOVE	R5	R0
      0x7C0C0400,  //  0004  CALL	R3	2
      0x4C100000,  //  0005  LDNIL	R4
      0x1C100604,  //  0006  EQ	R4	R3	R4
      0x78120008,  //  0007  JMPF	R4	#0011
      0xB8125A00,  //  0008  GETNGBL	R4	K45
      0x60140018,  //  0009  GETGBL	R5	G24
      0x5818002E,  //  000A  LDCONST	R6	K46
      0x5C1C0000,  //  000B  MOVE	R7	R0
      0x7C140400,  //  000C  CALL	R5	2
      0x5818002F,  //  000D  LDCONST	R6	K47
      0x7C100400,  //  000E  CALL	R4	2
      0x4C100000,  //  000F  LDNIL	R4
      0x80040800,  //  0010  RET	1	R4
      0x8C100730,  //  0011  GETMET	R4	R3	K48
      0x58180031,  //  0012  LDCONST	R6	K49
      0x7C100400,  //  0013  CALL	R4	2
      0x78120007,  //  0014  JMPF	R4	#001D
      0x8C100730,  //  0015  GETMET	R4	R3	K48
      0x58180032,  //  0016  LDCONST	R6	K50
      0x7C100400,  //  0017  CALL	R4	2
      0x78120003,  //  0018  JMPF	R4	#001D
      0x8C100730,  //  0019  GETMET	R4	R3	K48
      0x58180033,  //  001A  LDCONST	R6	K51
      0x7C100400,  //  001B  CALL	R4	2
      0x74120007,  //  001C  JMPT	R4	#0025
      0xB8125A00,  //  001D  GETNGBL	R4	K45
      0x60140018,  //  001E  GETGBL	R5	G24
      0x58180034,  //  001F  LDCONST	R6	K52
      0x5C1C0600,  //  0020  MOVE	R7	R3
      0x7C140400,  //  0021  CALL	R5	2
      0x7C100200,  //  0022  CALL	R4	1
      0x4C100000,  //  0023  LDNIL	R4
      0x80040800,  //  0024  RET	1	R4
      0x60100013,  //  0025  GETGBL	R4	G19
      0x7C100000,  //  0026  CALL	R4	0
      0x94140731,  //  0027  GETIDX	R5	R3	K49
      0x98126205,  //  0028  SETIDX	R4	K49	R5
      0x94140732,  //  0029  GETIDX	R5	R3	K50
      0x98126405,  //  002A  SETIDX	R4	K50	R5
      0x60140009,  //  002B  GETGBL	R5	G9
      0x94180733,  //  002C  GETIDX	R6	R3	K51
      0x7C140200,  //  002D  CALL	R5	1
      0x98126605,  //  002E  SETIDX	R4	K51	R5
      0x8C140713,  //  002F  GETMET	R5	R3	K19
      0x581C0035,  //  0030  LDCONST	R7	K53
      0x58200036,  //  0031  LDCONST	R8	K54
      0x7C140600,  //  0032  CALL	R5	3
      0x98126A05,  //  0033  SETIDX	R4	K53	R5
      0x8C140713,  //  0034  GETMET	R5	R3	K19
      0x581C0037,  //  0035  LDCONST	R7	K55
      0x58200038,  //  0036  LDCONST	R8	K56
      0x7C140600,  //  0037  CALL	R5	3
      0x98126E05,  //  0038  SETIDX	R4	K55	R5
      0x80040800,  //  0039  RET	1	R4
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: web_add_button
********************************************************************/
be_local_closure(class_Extension_manager_web_add_button,   /* name */
  be_nested_proto(
    5,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_web_add_button,
    &be_const_str_solidified,
    ( &(const binstruction[ 5]) {  /* code */
      0xA4060000,  //  0000  IMPORT	R1	K0
      0x8C080339,  //  0001  GETMET	R2	R1	K57
      0x5810003A,  //  0002  LDCONST	R4	K58
      0x7C080400,  //  0003  CALL	R2	2
      0x80000000,  //  0004  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: list_extensions_in_fs
********************************************************************/
be_local_closure(class_Extension_manager_list_extensions_in_fs,   /* name */
  be_nested_proto(
    10,                          /* nstack */
    0,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_list_extensions_in_fs,
    &be_const_str_solidified,
    ( &(const binstruction[36]) {  /* code */
      0x58000006,  //  0000  LDCONST	R0	K6
      0xA4060E00,  //  0001  IMPORT	R1	K7
      0xB80A7600,  //  0002  GETNGBL	R2	K59
      0x7C080000,  //  0003  CALL	R2	0
      0x600C0010,  //  0004  GETGBL	R3	G16
      0x8C10013C,  //  0005  GETMET	R4	R0	K60
      0x7C100200,  //  0006  CALL	R4	1
      0x7C0C0200,  //  0007  CALL	R3	1
      0xA8020016,  //  0008  EXBLK	0	#0020
      0x5C100600,  //  0009  MOVE	R4	R3
      0x7C100000,  //  000A  CALL	R4	0
      0xB8161000,  //  000B  GETNGBL	R5	K8
      0x8C140B3D,  //  000C  GETMET	R5	R5	K61
      0x5C1C0800,  //  000D  MOVE	R7	R4
      0x7C140400,  //  000E  CALL	R5	2
      0x4C180000,  //  000F  LDNIL	R6
      0x20180A06,  //  0010  NE	R6	R5	R6
      0x781A0005,  //  0011  JMPF	R6	#0018
      0x8C180B13,  //  0012  GETMET	R6	R5	K19
      0x58200031,  //  0013  LDCONST	R8	K49
      0x7C180400,  //  0014  CALL	R6	2
      0x781A0000,  //  0015  JMPF	R6	#0017
      0x98080C04,  //  0016  SETIDX	R2	R6	R4
      0x70020006,  //  0017  JMP		#001F
      0xB81A5A00,  //  0018  GETNGBL	R6	K45
      0x601C0018,  //  0019  GETGBL	R7	G24
      0x5820003E,  //  001A  LDCONST	R8	K62
      0x5C240800,  //  001B  MOVE	R9	R4
      0x7C1C0400,  //  001C  CALL	R7	2
      0x5820002F,  //  001D  LDCONST	R8	K47
      0x7C180400,  //  001E  CALL	R6	2
      0x7001FFE8,  //  001F  JMP		#0009
      0x580C0029,  //  0020  LDCONST	R3	K41
      0xAC0C0200,  //  0021  CATCH	R3	1	0
      0xB0080000,  //  0022  RAISE	2	R0	R0
      0x80040400,  //  0023  RET	1	R2
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: version_string
********************************************************************/
be_local_closure(class_Extension_manager_version_string,   /* name */
  be_nested_proto(
    8,                          /* nstack */
    1,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_version_string,
    &be_const_str_solidified,
    ( &(const binstruction[19]) {  /* code */
      0x58040006,  //  0000  LDCONST	R1	K6
      0x60080018,  //  0001  GETGBL	R2	G24
      0x580C003F,  //  0002  LDCONST	R3	K63
      0x54120017,  //  0003  LDINT	R4	24
      0x3C100004,  //  0004  SHR	R4	R0	R4
      0x541600FE,  //  0005  LDINT	R5	255
      0x2C100805,  //  0006  AND	R4	R4	R5
      0x5416000F,  //  0007  LDINT	R5	16
      0x3C140005,  //  0008  SHR	R5	R0	R5
      0x541A00FE,  //  0009  LDINT	R6	255
      0x2C140A06,  //  000A  AND	R5	R5	R6
      0x541A0007,  //  000B  LDINT	R6	8
      0x3C180006,  //  000C  SHR	R6	R0	R6
      0x541E00FE,  //  000D  LDINT	R7	255
      0x2C180C07,  //  000E  AND	R6	R6	R7
      0x541E00FE,  //  000F  LDINT	R7	255
      0x2C1C0007,  //  0010  AND	R7	R0	R7
      0x7C080A00,  //  0011  CALL	R2	5
      0x80040400,  //  0012  RET	1	R2
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: install_from_store
********************************************************************/
be_local_closure(class_Extension_manager_install_from_store,   /* name */
  be_nested_proto(
    16,                          /* nstack */
    2,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_install_from_store,
    &be_const_str_solidified,
    ( &(const binstruction[127]) {  /* code */
      0xA40A0E00,  //  0000  IMPORT	R2	K7
      0xA40E2800,  //  0001  IMPORT	R3	K20
      0x8C100111,  //  0002  GETMET	R4	R0	K17
      0x5C180200,  //  0003  MOVE	R6	R1
      0x7C100400,  //  0004  CALL	R4	2
      0x00100923,  //  0005  ADD	R4	R4	K35
      0x5C040800,  //  0006  MOVE	R1	R4
      0x60100018,  //  0007  GETGBL	R4	G24
      0x58140040,  //  0008  LDCONST	R5	K64
      0x88180141,  //  0009  GETMBR	R6	R0	K65
      0x881C0142,  //  000A  GETMBR	R7	R0	K66
      0x5C200200,  //  000B  MOVE	R8	R1
      0x7C100800,  //  000C  CALL	R4	4
      0x8C140143,  //  000D  GETMET	R5	R0	K67
      0x7C140200,  //  000E  CALL	R5	1
      0x60180018,  //  000F  GETGBL	R6	G24
      0x581C0040,  //  0010  LDCONST	R7	K64
      0x5C200A00,  //  0011  MOVE	R8	R5
      0x88240142,  //  0012  GETMBR	R9	R0	K66
      0x5C280200,  //  0013  MOVE	R10	R1
      0x7C180800,  //  0014  CALL	R6	4
      0xA8020059,  //  0015  EXBLK	0	#0070
      0x8C1C0144,  //  0016  GETMET	R7	R0	K68
      0x88240125,  //  0017  GETMBR	R9	R0	K37
      0x7C1C0400,  //  0018  CALL	R7	2
      0x601C0018,  //  0019  GETGBL	R7	G24
      0x58200045,  //  001A  LDCONST	R8	K69
      0x88240125,  //  001B  GETMBR	R9	R0	K37
      0x5C280200,  //  001C  MOVE	R10	R1
      0x7C1C0600,  //  001D  CALL	R7	3
      0xB8228C00,  //  001E  GETNGBL	R8	K70
      0x7C200000,  //  001F  CALL	R8	0
      0xB8265A00,  //  0020  GETNGBL	R9	K45
      0x60280018,  //  0021  GETGBL	R10	G24
      0x582C0047,  //  0022  LDCONST	R11	K71
      0x5C300C00,  //  0023  MOVE	R12	R6
      0x7C280400,  //  0024  CALL	R10	2
      0x582C002F,  //  0025  LDCONST	R11	K47
      0x7C240400,  //  0026  CALL	R9	2
      0x8C241148,  //  0027  GETMET	R9	R8	K72
      0x5C2C0C00,  //  0028  MOVE	R11	R6
      0x7C240400,  //  0029  CALL	R9	2
      0x8C241149,  //  002A  GETMET	R9	R8	K73
      0x7C240200,  //  002B  CALL	R9	1
      0x542A00C7,  //  002C  LDINT	R10	200
      0x2028120A,  //  002D  NE	R10	R9	R10
      0x782A0021,  //  002E  JMPF	R10	#0051
      0x8C28114A,  //  002F  GETMET	R10	R8	K74
      0x7C280200,  //  0030  CALL	R10	1
      0xB82A8C00,  //  0031  GETNGBL	R10	K70
      0x7C280000,  //  0032  CALL	R10	0
      0x5C201400,  //  0033  MOVE	R8	R10
      0x88280141,  //  0034  GETMBR	R10	R0	K65
      0x20281405,  //  0035  NE	R10	R10	R5
      0x782A000C,  //  0036  JMPF	R10	#0044
      0xB82A5A00,  //  0037  GETNGBL	R10	K45
      0x602C0018,  //  0038  GETGBL	R11	G24
      0x58300047,  //  0039  LDCONST	R12	K71
      0x5C340800,  //  003A  MOVE	R13	R4
      0x7C2C0400,  //  003B  CALL	R11	2
      0x5830002F,  //  003C  LDCONST	R12	K47
      0x7C280400,  //  003D  CALL	R10	2
      0x8C281148,  //  003E  GETMET	R10	R8	K72
      0x5C300800,  //  003F  MOVE	R12	R4
      0x7C280400,  //  0040  CALL	R10	2
      0x8C281149,  //  0041  GETMET	R10	R8	K73
      0x7C280200,  //  0042  CALL	R10	1
      0x5C241400,  //  0043  MOVE	R9	R10
      0x542A00C7,  //  0044  LDINT	R10	200
      0x2028120A,  //  0045  NE	R10	R9	R10
      0x782A0009,  //  0046  JMPF	R10	#0051
      0xB82A5A00,  //  0047  GETNGBL	R10	K45
      0x602C0018,  //  0048  GETGBL	R11	G24
      0x5830004B,  //  0049  LDCONST	R12	K75
      0x5C341200,  //  004A  MOVE	R13	R9
      0x7C2C0400,  //  004B  CALL	R11	2
      0x58300010,  //  004C  LDCONST	R12	K16
      0x7C280400,  //  004D  CALL	R10	2
      0x50280000,  //  004E  LDBOOL	R10	0	0
      0xA8040001,  //  004F  EXBLK	1	1
      0x80041400,  //  0050  RET	1	R10
      0x8C28114C,  //  0051  GETMET	R10	R8	K76
      0x5C300E00,  //  0052  MOVE	R12	R7
      0x7C280400,  //  0053  CALL	R10	2
      0x8C2C114A,  //  0054  GETMET	R11	R8	K74
      0x7C2C0200,  //  0055  CALL	R11	1
      0x242C150F,  //  0056  GT	R11	R10	K15
      0x782E000F,  //  0057  JMPF	R11	#0068
      0x8C2C071B,  //  0058  GETMET	R11	R3	K27
      0x5C340E00,  //  0059  MOVE	R13	R7
      0x7C2C0400,  //  005A  CALL	R11	2
      0x782E000B,  //  005B  JMPF	R11	#0068
      0xB82E5A00,  //  005C  GETNGBL	R11	K45
      0x60300018,  //  005D  GETGBL	R12	G24
      0x5834004D,  //  005E  LDCONST	R13	K77
      0x5C380E00,  //  005F  MOVE	R14	R7
      0x5C3C1400,  //  0060  MOVE	R15	R10
      0x7C300600,  //  0061  CALL	R12	3
      0x5834002F,  //  0062  LDCONST	R13	K47
      0x7C2C0400,  //  0063  CALL	R11	2
      0x502C0200,  //  0064  LDBOOL	R11	1	0
      0xA8040001,  //  0065  EXBLK	1	1
      0x80041600,  //  0066  RET	1	R11
      0x70020005,  //  0067  JMP		#006E
      0x602C0018,  //  0068  GETGBL	R11	G24
      0x5830004E,  //  0069  LDCONST	R12	K78
      0x5C340E00,  //  006A  MOVE	R13	R7
      0x5C381400,  //  006B  MOVE	R14	R10
      0x7C2C0600,  //  006C  CALL	R11	3
      0xB0063E0B,  //  006D  RAISE	1	K31	R11
      0xA8040001,  //  006E  EXBLK	1	1
      0x7002000D,  //  006F  JMP		#007E
      0xAC1C0002,  //  0070  CATCH	R7	0	2
      0x7002000A,  //  0071  JMP		#007D
      0xB8265A00,  //  0072  GETNGBL	R9	K45
      0x60280018,  //  0073  GETGBL	R10	G24
      0x582C004F,  //  0074  LDCONST	R11	K79
      0x5C300E00,  //  0075  MOVE	R12	R7
      0x5C341000,  //  0076  MOVE	R13	R8
      0x7C280600,  //  0077  CALL	R10	3
      0x582C0010,  //  0078  LDCONST	R11	K16
      0x7C240400,  //  0079  CALL	R9	2
      0x50240000,  //  007A  LDBOOL	R9	0	0
      0x80041200,  //  007B  RET	1	R9
      0x70020000,  //  007C  JMP		#007E
      0xB0080000,  //  007D  RAISE	2	R0	R0
      0x80000000,  //  007E  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: page_extensions_ctl
********************************************************************/
be_local_closure(class_Extension_manager_page_extensions_ctl,   /* name */
  be_nested_proto(
    14,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_page_extensions_ctl,
    &be_const_str_solidified,
    ( &(const binstruction[121]) {  /* code */
      0xA4060000,  //  0000  IMPORT	R1	K0
      0xA40A2800,  //  0001  IMPORT	R2	K20
      0xA40E0E00,  //  0002  IMPORT	R3	K7
      0x8C100301,  //  0003  GETMET	R4	R1	K1
      0x7C100200,  //  0004  CALL	R4	1
      0x74120001,  //  0005  JMPT	R4	#0008
      0x4C100000,  //  0006  LDNIL	R4
      0x80040800,  //  0007  RET	1	R4
      0xA802004D,  //  0008  EXBLK	0	#0057
      0x8C100350,  //  0009  GETMET	R4	R1	K80
      0x5818000F,  //  000A  LDCONST	R6	K15
      0x7C100400,  //  000B  CALL	R4	2
      0x9414090F,  //  000C  GETIDX	R5	R4	K15
      0x401A4151,  //  000D  CONNECT	R6	K32	K81
      0x94180806,  //  000E  GETIDX	R6	R4	R6
      0x1C1C0B52,  //  000F  EQ	R7	R5	K82
      0x741E0001,  //  0010  JMPT	R7	#0013
      0x1C1C0B53,  //  0011  EQ	R7	R5	K83
      0x781E0004,  //  0012  JMPF	R7	#0018
      0x8C1C0115,  //  0013  GETMET	R7	R0	K21
      0x5C240C00,  //  0014  MOVE	R9	R6
      0x1C280B52,  //  0015  EQ	R10	R5	K82
      0x7C1C0600,  //  0016  CALL	R7	3
      0x70020037,  //  0017  JMP		#0050
      0x1C1C0B54,  //  0018  EQ	R7	R5	K84
      0x741E0001,  //  0019  JMPT	R7	#001C
      0x1C1C0B55,  //  001A  EQ	R7	R5	K85
      0x781E0004,  //  001B  JMPF	R7	#0021
      0x8C1C0156,  //  001C  GETMET	R7	R0	K86
      0x5C240C00,  //  001D  MOVE	R9	R6
      0x1C280B55,  //  001E  EQ	R10	R5	K85
      0x7C1C0600,  //  001F  CALL	R7	3
      0x7002002E,  //  0020  JMP		#0050
      0x1C1C0B57,  //  0021  EQ	R7	R5	K87
      0x781E0003,  //  0022  JMPF	R7	#0027
      0x8C1C0158,  //  0023  GETMET	R7	R0	K88
      0x5C240C00,  //  0024  MOVE	R9	R6
      0x7C1C0400,  //  0025  CALL	R7	2
      0x70020028,  //  0026  JMP		#0050
      0x1C1C0B59,  //  0027  EQ	R7	R5	K89
      0x781E0009,  //  0028  JMPF	R7	#0033
      0x8C1C0115,  //  0029  GETMET	R7	R0	K21
      0x5C240C00,  //  002A  MOVE	R9	R6
      0x50280000,  //  002B  LDBOOL	R10	0	0
      0x7C1C0600,  //  002C  CALL	R7	3
      0x8C1C015A,  //  002D  GETMET	R7	R0	K90
      0x8C240111,  //  002E  GETMET	R9	R0	K17
      0x5C2C0C00,  //  002F  MOVE	R11	R6
      0x7C240400,  //  0030  CALL	R9	2
      0x7C1C0400,  //  0031  CALL	R7	2
      0x7002001C,  //  0032  JMP		#0050
      0x1C1C0B5B,  //  0033  EQ	R7	R5	K91
      0x741E0001,  //  0034  JMPT	R7	#0037
      0x1C1C0B5C,  //  0035  EQ	R7	R5	K92
      0x781E0011,  //  0036  JMPF	R7	#0049
      0x8C1C015A,  //  0037  GETMET	R7	R0	K90
      0x8C240111,  //  0038  GETMET	R9	R0	K17
      0x5C2C0C00,  //  0039  MOVE	R11	R6
      0x7C240400,  //  003A  CALL	R9	2
      0x7C1C0400,  //  003B  CALL	R7	2
      0x781E000A,  //  003C  JMPF	R7	#0048
      0x1C200B5C,  //  003D  EQ	R8	R5	K92
      0x78220004,  //  003E  JMPF	R8	#0044
      0x8C200115,  //  003F  GETMET	R8	R0	K21
      0x5C280C00,  //  0040  MOVE	R10	R6
      0x502C0200,  //  0041  LDBOOL	R11	1	0
      0x7C200600,  //  0042  CALL	R8	3
      0x70020003,  //  0043  JMP		#0048
      0x8C200156,  //  0044  GETMET	R8	R0	K86
      0x5C280C00,  //  0045  MOVE	R10	R6
      0x502C0000,  //  0046  LDBOOL	R11	0	0
      0x7C200600,  //  0047  CALL	R8	3
      0x70020006,  //  0048  JMP		#0050
      0xB81E5A00,  //  0049  GETNGBL	R7	K45
      0x60200018,  //  004A  GETGBL	R8	G24
      0x5824005D,  //  004B  LDCONST	R9	K93
      0x5C280800,  //  004C  MOVE	R10	R4
      0x7C200400,  //  004D  CALL	R8	2
      0x5824002F,  //  004E  LDCONST	R9	K47
      0x7C1C0400,  //  004F  CALL	R7	2
      0x8C1C035E,  //  0050  GETMET	R7	R1	K94
      0x60240018,  //  0051  GETGBL	R9	G24
      0x58280018,  //  0052  LDCONST	R10	K24
      0x7C240200,  //  0053  CALL	R9	1
      0x7C1C0400,  //  0054  CALL	R7	2
      0xA8040001,  //  0055  EXBLK	1	1
      0x70020020,  //  0056  JMP		#0078
      0xAC100002,  //  0057  CATCH	R4	0	2
      0x7002001D,  //  0058  JMP		#0077
      0xB81A5A00,  //  0059  GETNGBL	R6	K45
      0x601C0018,  //  005A  GETGBL	R7	G24
      0x5820005F,  //  005B  LDCONST	R8	K95
      0x5C240800,  //  005C  MOVE	R9	R4
      0x5C280A00,  //  005D  MOVE	R10	R5
      0x7C1C0600,  //  005E  CALL	R7	3
      0x58200010,  //  005F  LDCONST	R8	K16
      0x7C180400,  //  0060  CALL	R6	2
      0x8C180360,  //  0061  GETMET	R6	R1	K96
      0x58200061,  //  0062  LDCONST	R8	K97
      0x7C180400,  //  0063  CALL	R6	2
      0x8C180362,  //  0064  GETMET	R6	R1	K98
      0x7C180200,  //  0065  CALL	R6	1
      0x8C180339,  //  0066  GETMET	R6	R1	K57
      0x60200018,  //  0067  GETGBL	R8	G24
      0x58240063,  //  0068  LDCONST	R9	K99
      0x8C280364,  //  0069  GETMET	R10	R1	K100
      0x5C300800,  //  006A  MOVE	R12	R4
      0x7C280400,  //  006B  CALL	R10	2
      0x8C2C0364,  //  006C  GETMET	R11	R1	K100
      0x5C340A00,  //  006D  MOVE	R13	R5
      0x7C2C0400,  //  006E  CALL	R11	2
      0x7C200600,  //  006F  CALL	R8	3
      0x7C180400,  //  0070  CALL	R6	2
      0x8C180365,  //  0071  GETMET	R6	R1	K101
      0x88200366,  //  0072  GETMBR	R8	R1	K102
      0x7C180400,  //  0073  CALL	R6	2
      0x8C180367,  //  0074  GETMET	R6	R1	K103
      0x7C180200,  //  0075  CALL	R6	1
      0x70020000,  //  0076  JMP		#0078
      0xB0080000,  //  0077  RAISE	2	R0	R0
      0x80000000,  //  0078  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: page_extensions_mgr
********************************************************************/
be_local_closure(class_Extension_manager_page_extensions_mgr,   /* name */
  be_nested_proto(
    22,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_page_extensions_mgr,
    &be_const_str_solidified,
    ( &(const binstruction[162]) {  /* code */
      0xA4060000,  //  0000  IMPORT	R1	K0
      0xA40A0E00,  //  0001  IMPORT	R2	K7
      0x8C0C0360,  //  0002  GETMET	R3	R1	K96
      0x58140068,  //  0003  LDCONST	R5	K104
      0x7C0C0400,  //  0004  CALL	R3	2
      0x8C0C0362,  //  0005  GETMET	R3	R1	K98
      0x7C0C0200,  //  0006  CALL	R3	1
      0x8C0C0339,  //  0007  GETMET	R3	R1	K57
      0x58140069,  //  0008  LDCONST	R5	K105
      0x7C0C0400,  //  0009  CALL	R3	2
      0x8C0C0339,  //  000A  GETMET	R3	R1	K57
      0x5814006A,  //  000B  LDCONST	R5	K106
      0x7C0C0400,  //  000C  CALL	R3	2
      0x8C0C0339,  //  000D  GETMET	R3	R1	K57
      0x5814006B,  //  000E  LDCONST	R5	K107
      0x7C0C0400,  //  000F  CALL	R3	2
      0x8C0C016C,  //  0010  GETMET	R3	R0	K108
      0x50140200,  //  0011  LDBOOL	R5	1	0
      0x7C0C0400,  //  0012  CALL	R3	2
      0x6010000C,  //  0013  GETGBL	R4	G12
      0x5C140600,  //  0014  MOVE	R5	R3
      0x7C100200,  //  0015  CALL	R4	1
      0x2410090F,  //  0016  GT	R4	R4	K15
      0x78120077,  //  0017  JMPF	R4	#0090
      0x5810000F,  //  0018  LDCONST	R4	K15
      0x6014000C,  //  0019  GETGBL	R5	G12
      0x5C180600,  //  001A  MOVE	R6	R3
      0x7C140200,  //  001B  CALL	R5	1
      0x14140805,  //  001C  LT	R5	R4	R5
      0x78160070,  //  001D  JMPF	R5	#008F
      0x2414090F,  //  001E  GT	R5	R4	K15
      0x78160002,  //  001F  JMPF	R5	#0023
      0x8C140339,  //  0020  GETMET	R5	R1	K57
      0x581C006D,  //  0021  LDCONST	R7	K109
      0x7C140400,  //  0022  CALL	R5	2
      0x8C14076E,  //  0023  GETMET	R5	R3	K110
      0x5C1C0800,  //  0024  MOVE	R7	R4
      0x7C140400,  //  0025  CALL	R5	2
      0x8C180111,  //  0026  GETMET	R6	R0	K17
      0x5C200A00,  //  0027  MOVE	R8	R5
      0x7C180400,  //  0028  CALL	R6	2
      0x8C1C0364,  //  0029  GETMET	R7	R1	K100
      0x5C240C00,  //  002A  MOVE	R9	R6
      0x7C1C0400,  //  002B  CALL	R7	2
      0xB8221000,  //  002C  GETNGBL	R8	K8
      0x8C20113D,  //  002D  GETMET	R8	R8	K61
      0x5C280A00,  //  002E  MOVE	R10	R5
      0x7C200400,  //  002F  CALL	R8	2
      0xB8261000,  //  0030  GETNGBL	R9	K8
      0x8824136F,  //  0031  GETMBR	R9	R9	K111
      0x78260005,  //  0032  JMPF	R9	#0039
      0xB8261000,  //  0033  GETNGBL	R9	K8
      0x8824136F,  //  0034  GETMBR	R9	R9	K111
      0x8C241330,  //  0035  GETMET	R9	R9	K48
      0x5C2C0A00,  //  0036  MOVE	R11	R5
      0x7C240400,  //  0037  CALL	R9	2
      0x70020000,  //  0038  JMP		#003A
      0x50240000,  //  0039  LDBOOL	R9	0	0
      0x78260001,  //  003A  JMPF	R9	#003D
      0x58280070,  //  003B  LDCONST	R10	K112
      0x70020000,  //  003C  JMP		#003E
      0x58280038,  //  003D  LDCONST	R10	K56
      0x8C2C1113,  //  003E  GETMET	R11	R8	K19
      0x58340071,  //  003F  LDCONST	R13	K113
      0x50380000,  //  0040  LDBOOL	R14	0	0
      0x7C2C0600,  //  0041  CALL	R11	3
      0x58300072,  //  0042  LDCONST	R12	K114
      0x58340073,  //  0043  LDCONST	R13	K115
      0x8C380339,  //  0044  GETMET	R14	R1	K57
      0x58400074,  //  0045  LDCONST	R16	K116
      0x7C380400,  //  0046  CALL	R14	2
      0x8C380339,  //  0047  GETMET	R14	R1	K57
      0x60400018,  //  0048  GETGBL	R16	G24
      0x58440075,  //  0049  LDCONST	R17	K117
      0x5C480E00,  //  004A  MOVE	R18	R7
      0x8C4C0364,  //  004B  GETMET	R19	R1	K100
      0x94541131,  //  004C  GETIDX	R21	R8	K49
      0x7C4C0400,  //  004D  CALL	R19	2
      0x5C501400,  //  004E  MOVE	R20	R10
      0x7C400800,  //  004F  CALL	R16	4
      0x7C380400,  //  0050  CALL	R14	2
      0x8C380339,  //  0051  GETMET	R14	R1	K57
      0x60400018,  //  0052  GETGBL	R16	G24
      0x58440076,  //  0053  LDCONST	R17	K118
      0x8C480364,  //  0054  GETMET	R18	R1	K100
      0x94501135,  //  0055  GETIDX	R20	R8	K53
      0x7C480400,  //  0056  CALL	R18	2
      0x7C400400,  //  0057  CALL	R16	2
      0x7C380400,  //  0058  CALL	R14	2
      0x8C380339,  //  0059  GETMET	R14	R1	K57
      0x58400077,  //  005A  LDCONST	R16	K119
      0x7C380400,  //  005B  CALL	R14	2
      0x8C380339,  //  005C  GETMET	R14	R1	K57
      0x58400078,  //  005D  LDCONST	R16	K120
      0x7C380400,  //  005E  CALL	R14	2
      0x8C380339,  //  005F  GETMET	R14	R1	K57
      0x60400018,  //  0060  GETGBL	R16	G24
      0x58440079,  //  0061  LDCONST	R17	K121
      0x78260001,  //  0062  JMPF	R9	#0065
      0x5C481800,  //  0063  MOVE	R18	R12
      0x70020000,  //  0064  JMP		#0066
      0x5C481A00,  //  0065  MOVE	R18	R13
      0x78260001,  //  0066  JMPF	R9	#0069
      0x584C0053,  //  0067  LDCONST	R19	K83
      0x70020000,  //  0068  JMP		#006A
      0x584C0052,  //  0069  LDCONST	R19	K82
      0x5C500E00,  //  006A  MOVE	R20	R7
      0x78260001,  //  006B  JMPF	R9	#006E
      0x5854007A,  //  006C  LDCONST	R21	K122
      0x70020000,  //  006D  JMP		#006F
      0x5854007B,  //  006E  LDCONST	R21	K123
      0x7C400A00,  //  006F  CALL	R16	5
      0x7C380400,  //  0070  CALL	R14	2
      0x8C380339,  //  0071  GETMET	R14	R1	K57
      0x60400018,  //  0072  GETGBL	R16	G24
      0x5844007C,  //  0073  LDCONST	R17	K124
      0x782E0001,  //  0074  JMPF	R11	#0077
      0x58480038,  //  0075  LDCONST	R18	K56
      0x70020000,  //  0076  JMP		#0078
      0x5C481A00,  //  0077  MOVE	R18	R13
      0x782E0001,  //  0078  JMPF	R11	#007B
      0x584C0054,  //  0079  LDCONST	R19	K84
      0x70020000,  //  007A  JMP		#007C
      0x584C0055,  //  007B  LDCONST	R19	K85
      0x5C500E00,  //  007C  MOVE	R20	R7
      0x782E0001,  //  007D  JMPF	R11	#0080
      0x5854007D,  //  007E  LDCONST	R21	K125
      0x70020000,  //  007F  JMP		#0081
      0x5854007E,  //  0080  LDCONST	R21	K126
      0x7C400A00,  //  0081  CALL	R16	5
      0x7C380400,  //  0082  CALL	R14	2
      0x8C380339,  //  0083  GETMET	R14	R1	K57
      0x60400018,  //  0084  GETGBL	R16	G24
      0x5844007F,  //  0085  LDCONST	R17	K127
      0x5C480E00,  //  0086  MOVE	R18	R7
      0x5C4C0E00,  //  0087  MOVE	R19	R7
      0x7C400600,  //  0088  CALL	R16	3
      0x7C380400,  //  0089  CALL	R14	2
      0x8C380339,  //  008A  GETMET	R14	R1	K57
      0x58400080,  //  008B  LDCONST	R16	K128
      0x7C380400,  //  008C  CALL	R14	2
      0x00100920,  //  008D  ADD	R4	R4	K32
      0x7001FF89,  //  008E  JMP		#0019
      0x70020002,  //  008F  JMP		#0093
      0x8C100339,  //  0090  GETMET	R4	R1	K57
      0x58180081,  //  0091  LDCONST	R6	K129
      0x7C100400,  //  0092  CALL	R4	2
      0x8C100339,  //  0093  GETMET	R4	R1	K57
      0x58180082,  //  0094  LDCONST	R6	K130
      0x7C100400,  //  0095  CALL	R4	2
      0x8C100339,  //  0096  GETMET	R4	R1	K57
      0x58180083,  //  0097  LDCONST	R6	K131
      0x7C100400,  //  0098  CALL	R4	2
      0x8C100339,  //  0099  GETMET	R4	R1	K57
      0x58180084,  //  009A  LDCONST	R6	K132
      0x7C100400,  //  009B  CALL	R4	2
      0x8C100365,  //  009C  GETMET	R4	R1	K101
      0x88180366,  //  009D  GETMBR	R6	R1	K102
      0x7C100400,  //  009E  CALL	R4	2
      0x8C100367,  //  009F  GETMET	R4	R1	K103
      0x7C100200,  //  00A0  CALL	R4	1
      0x80000000,  //  00A1  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: load_manifest
********************************************************************/
be_local_closure(class_Extension_manager_load_manifest,   /* name */
  be_nested_proto(
    12,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_load_manifest,
    &be_const_str_solidified,
    ( &(const binstruction[101]) {  /* code */
      0xA8020055,  //  0000  EXBLK	0	#0057
      0xB8061000,  //  0001  GETNGBL	R1	K8
      0x8C040385,  //  0002  GETMET	R1	R1	K133
      0x7C040200,  //  0003  CALL	R1	1
      0x60080018,  //  0004  GETGBL	R2	G24
      0x580C0086,  //  0005  LDCONST	R3	K134
      0xB8121000,  //  0006  GETNGBL	R4	K8
      0x8C100933,  //  0007  GETMET	R4	R4	K51
      0x7C100200,  //  0008  CALL	R4	1
      0x7C080400,  //  0009  CALL	R2	2
      0x600C0018,  //  000A  GETGBL	R3	G24
      0x58100087,  //  000B  LDCONST	R4	K135
      0x88140141,  //  000C  GETMBR	R5	R0	K65
      0x88180188,  //  000D  GETMBR	R6	R0	K136
      0x5C1C0200,  //  000E  MOVE	R7	R1
      0x5C200400,  //  000F  MOVE	R8	R2
      0x7C0C0A00,  //  0010  CALL	R3	5
      0x8C100143,  //  0011  GETMET	R4	R0	K67
      0x7C100200,  //  0012  CALL	R4	1
      0x60140018,  //  0013  GETGBL	R5	G24
      0x58180087,  //  0014  LDCONST	R6	K135
      0x5C1C0800,  //  0015  MOVE	R7	R4
      0x88200188,  //  0016  GETMBR	R8	R0	K136
      0x5C240200,  //  0017  MOVE	R9	R1
      0x5C280400,  //  0018  MOVE	R10	R2
      0x7C140A00,  //  0019  CALL	R5	5
      0xB81A8C00,  //  001A  GETNGBL	R6	K70
      0x7C180000,  //  001B  CALL	R6	0
      0xB81E5A00,  //  001C  GETNGBL	R7	K45
      0x60200018,  //  001D  GETGBL	R8	G24
      0x58240089,  //  001E  LDCONST	R9	K137
      0x5C280A00,  //  001F  MOVE	R10	R5
      0x7C200400,  //  0020  CALL	R8	2
      0x5824002F,  //  0021  LDCONST	R9	K47
      0x7C1C0400,  //  0022  CALL	R7	2
      0x8C1C0D48,  //  0023  GETMET	R7	R6	K72
      0x5C240A00,  //  0024  MOVE	R9	R5
      0x7C1C0400,  //  0025  CALL	R7	2
      0x8C1C0D49,  //  0026  GETMET	R7	R6	K73
      0x7C1C0200,  //  0027  CALL	R7	1
      0x542200C7,  //  0028  LDINT	R8	200
      0x20200E08,  //  0029  NE	R8	R7	R8
      0x78220023,  //  002A  JMPF	R8	#004F
      0x8C200D4A,  //  002B  GETMET	R8	R6	K74
      0x7C200200,  //  002C  CALL	R8	1
      0xB8228C00,  //  002D  GETNGBL	R8	K70
      0x7C200000,  //  002E  CALL	R8	0
      0x5C181000,  //  002F  MOVE	R6	R8
      0x88200141,  //  0030  GETMBR	R8	R0	K65
      0x20201004,  //  0031  NE	R8	R8	R4
      0x7822000C,  //  0032  JMPF	R8	#0040
      0xB8225A00,  //  0033  GETNGBL	R8	K45
      0x60240018,  //  0034  GETGBL	R9	G24
      0x58280089,  //  0035  LDCONST	R10	K137
      0x5C2C0600,  //  0036  MOVE	R11	R3
      0x7C240400,  //  0037  CALL	R9	2
      0x5828002F,  //  0038  LDCONST	R10	K47
      0x7C200400,  //  0039  CALL	R8	2
      0x8C200D48,  //  003A  GETMET	R8	R6	K72
      0x5C280600,  //  003B  MOVE	R10	R3
      0x7C200400,  //  003C  CALL	R8	2
      0x8C200D49,  //  003D  GETMET	R8	R6	K73
      0x7C200200,  //  003E  CALL	R8	1
      0x5C1C1000,  //  003F  MOVE	R7	R8
      0x542200C7,  //  0040  LDINT	R8	200
      0x20200E08,  //  0041  NE	R8	R7	R8
      0x7822000B,  //  0042  JMPF	R8	#004F
      0xB8225A00,  //  0043  GETNGBL	R8	K45
      0x60240018,  //  0044  GETGBL	R9	G24
      0x5828008A,  //  0045  LDCONST	R10	K138
      0x5C2C0E00,  //  0046  MOVE	R11	R7
      0x7C240400,  //  0047  CALL	R9	2
      0x58280010,  //  0048  LDCONST	R10	K16
      0x7C200400,  //  0049  CALL	R8	2
      0x60200018,  //  004A  GETGBL	R8	G24
      0x5824008B,  //  004B  LDCONST	R9	K139
      0x5C280E00,  //  004C  MOVE	R10	R7
      0x7C200400,  //  004D  CALL	R8	2
      0xB0071808,  //  004E  RAISE	1	K140	R8
      0x8C200D8D,  //  004F  GETMET	R8	R6	K141
      0x7C200200,  //  0050  CALL	R8	1
      0x8C240D4A,  //  0051  GETMET	R9	R6	K74
      0x7C240200,  //  0052  CALL	R9	1
      0xA8040001,  //  0053  EXBLK	1	1
      0x80041000,  //  0054  RET	1	R8
      0xA8040001,  //  0055  EXBLK	1	1
      0x7002000C,  //  0056  JMP		#0064
      0xAC040002,  //  0057  CATCH	R1	0	2
      0x70020009,  //  0058  JMP		#0063
      0xB80E5A00,  //  0059  GETNGBL	R3	K45
      0x60100018,  //  005A  GETGBL	R4	G24
      0x5814004F,  //  005B  LDCONST	R5	K79
      0x5C180200,  //  005C  MOVE	R6	R1
      0x5C1C0400,  //  005D  MOVE	R7	R2
      0x7C100600,  //  005E  CALL	R4	3
      0x58140010,  //  005F  LDCONST	R5	K16
      0x7C0C0400,  //  0060  CALL	R3	2
      0xB0040202,  //  0061  RAISE	1	R1	R2
      0x70020000,  //  0062  JMP		#0064
      0xB0080000,  //  0063  RAISE	2	R0	R0
      0x80000000,  //  0064  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: list_installed_ext
********************************************************************/
be_local_closure(class_Extension_manager_list_installed_ext,   /* name */
  be_nested_proto(
    7,                          /* nstack */
    0,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_list_installed_ext,
    &be_const_str_solidified,
    ( &(const binstruction[19]) {  /* code */
      0x58000006,  //  0000  LDCONST	R0	K6
      0x60040013,  //  0001  GETGBL	R1	G19
      0x7C040000,  //  0002  CALL	R1	0
      0x60080010,  //  0003  GETGBL	R2	G16
      0x8C0C013C,  //  0004  GETMET	R3	R0	K60
      0x7C0C0200,  //  0005  CALL	R3	1
      0x7C080200,  //  0006  CALL	R2	1
      0xA8020006,  //  0007  EXBLK	0	#000F
      0x5C0C0400,  //  0008  MOVE	R3	R2
      0x7C0C0000,  //  0009  CALL	R3	0
      0x8C100111,  //  000A  GETMET	R4	R0	K17
      0x5C180600,  //  000B  MOVE	R6	R3
      0x7C100400,  //  000C  CALL	R4	2
      0x98040803,  //  000D  SETIDX	R1	R4	R3
      0x7001FFF8,  //  000E  JMP		#0008
      0x58080029,  //  000F  LDCONST	R2	K41
      0xAC080200,  //  0010  CATCH	R2	1	0
      0xB0080000,  //  0011  RAISE	2	R0	R0
      0x80040200,  //  0012  RET	1	R1
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: enable_disable_ext
********************************************************************/
be_local_closure(class_Extension_manager_enable_disable_ext,   /* name */
  be_nested_proto(
    11,                          /* nstack */
    2,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_enable_disable_ext,
    &be_const_str_solidified,
    ( &(const binstruction[66]) {  /* code */
      0x58080006,  //  0000  LDCONST	R2	K6
      0xA40E0E00,  //  0001  IMPORT	R3	K7
      0x8C100511,  //  0002  GETMET	R4	R2	K17
      0x5C180000,  //  0003  MOVE	R6	R0
      0x7C100400,  //  0004  CALL	R4	2
      0x5C000800,  //  0005  MOVE	R0	R4
      0x8C100512,  //  0006  GETMET	R4	R2	K18
      0x7C100200,  //  0007  CALL	R4	1
      0x8C100913,  //  0008  GETMET	R4	R4	K19
      0x5C180000,  //  0009  MOVE	R6	R0
      0x7C100400,  //  000A  CALL	R4	2
      0x4C140000,  //  000B  LDNIL	R5
      0x20140805,  //  000C  NE	R5	R4	R5
      0x78160031,  //  000D  JMPF	R5	#0040
      0x4C140000,  //  000E  LDNIL	R5
      0x78060008,  //  000F  JMPF	R1	#0019
      0x8C180726,  //  0010  GETMET	R6	R3	K38
      0x5C200800,  //  0011  MOVE	R8	R4
      0x58240027,  //  0012  LDCONST	R9	K39
      0x7C180600,  //  0013  CALL	R6	3
      0x781A0003,  //  0014  JMPF	R6	#0019
      0x5419FFFD,  //  0015  LDINT	R6	-2
      0x401A1E06,  //  0016  CONNECT	R6	K15	R6
      0x94140806,  //  0017  GETIDX	R5	R4	R6
      0x70020008,  //  0018  JMP		#0022
      0x5C180200,  //  0019  MOVE	R6	R1
      0x741A0006,  //  001A  JMPT	R6	#0022
      0x8C180726,  //  001B  GETMET	R6	R3	K38
      0x5C200800,  //  001C  MOVE	R8	R4
      0x58240023,  //  001D  LDCONST	R9	K35
      0x7C180600,  //  001E  CALL	R6	3
      0x781A0001,  //  001F  JMPF	R6	#0022
      0x00180922,  //  0020  ADD	R6	R4	K34
      0x5C140C00,  //  0021  MOVE	R5	R6
      0x7816001C,  //  0022  JMPF	R5	#0040
      0xA41A2800,  //  0023  IMPORT	R6	K20
      0x8C1C0D8E,  //  0024  GETMET	R7	R6	K142
      0x5C240800,  //  0025  MOVE	R9	R4
      0x5C280A00,  //  0026  MOVE	R10	R5
      0x7C1C0600,  //  0027  CALL	R7	3
      0x781E0015,  //  0028  JMPF	R7	#003F
      0xB8221000,  //  0029  GETNGBL	R8	K8
      0x8820116F,  //  002A  GETMBR	R8	R8	K111
      0x4C240000,  //  002B  LDNIL	R9
      0x20201009,  //  002C  NE	R8	R8	R9
      0x78220010,  //  002D  JMPF	R8	#003F
      0xB8221000,  //  002E  GETNGBL	R8	K8
      0x8820116F,  //  002F  GETMBR	R8	R8	K111
      0x8C201130,  //  0030  GETMET	R8	R8	K48
      0x5C280800,  //  0031  MOVE	R10	R4
      0x7C200400,  //  0032  CALL	R8	2
      0x7822000A,  //  0033  JMPF	R8	#003F
      0xB8221000,  //  0034  GETNGBL	R8	K8
      0x8820116F,  //  0035  GETMBR	R8	R8	K111
      0xB8261000,  //  0036  GETNGBL	R9	K8
      0x8824136F,  //  0037  GETMBR	R9	R9	K111
      0x94241204,  //  0038  GETIDX	R9	R9	R4
      0x98200A09,  //  0039  SETIDX	R8	R5	R9
      0xB8221000,  //  003A  GETNGBL	R8	K8
      0x8820116F,  //  003B  GETMBR	R8	R8	K111
      0x8C201116,  //  003C  GETMET	R8	R8	K22
      0x5C280800,  //  003D  MOVE	R10	R4
      0x7C200400,  //  003E  CALL	R8	2
      0x80040E00,  //  003F  RET	1	R7
      0x50140000,  //  0040  LDBOOL	R5	0	0
      0x80040A00,  //  0041  RET	1	R5
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: run_stop_ext
********************************************************************/
be_local_closure(class_Extension_manager_run_stop_ext,   /* name */
  be_nested_proto(
    7,                          /* nstack */
    2,                          /* argc */
    12,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_run_stop_ext,
    &be_const_str_solidified,
    ( &(const binstruction[29]) {  /* code */
      0x58080006,  //  0000  LDCONST	R2	K6
      0x8C0C0511,  //  0001  GETMET	R3	R2	K17
      0x5C140000,  //  0002  MOVE	R5	R0
      0x7C0C0400,  //  0003  CALL	R3	2
      0x5C000600,  //  0004  MOVE	R0	R3
      0x8C0C0512,  //  0005  GETMET	R3	R2	K18
      0x7C0C0200,  //  0006  CALL	R3	1
      0x8C0C0713,  //  0007  GETMET	R3	R3	K19
      0x5C140000,  //  0008  MOVE	R5	R0
      0x7C0C0400,  //  0009  CALL	R3	2
      0x4C100000,  //  000A  LDNIL	R4
      0x20100604,  //  000B  NE	R4	R3	R4
      0x7812000C,  //  000C  JMPF	R4	#001A
      0x78060005,  //  000D  JMPF	R1	#0014
      0xB8121000,  //  000E  GETNGBL	R4	K8
      0x8C10092C,  //  000F  GETMET	R4	R4	K44
      0x5C180600,  //  0010  MOVE	R6	R3
      0x7C100400,  //  0011  CALL	R4	2
      0x80040800,  //  0012  RET	1	R4
      0x70020004,  //  0013  JMP		#0019
      0xB8121000,  //  0014  GETNGBL	R4	K8
      0x8C10098F,  //  0015  GETMET	R4	R4	K143
      0x5C180600,  //  0016  MOVE	R6	R3
      0x7C100400,  //  0017  CALL	R4	2
      0x80040800,  //  0018  RET	1	R4
      0x70020001,  //  0019  JMP		#001C
      0x50100000,  //  001A  LDBOOL	R4	0	0
      0x80040800,  //  001B  RET	1	R4
      0x80000000,  //  001C  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: page_extensions_store
********************************************************************/
be_local_closure(class_Extension_manager_page_extensions_store,   /* name */
  be_nested_proto(
    32,                          /* nstack */
    1,                          /* argc */
    10,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    &be_ktab_class_Extension_manager,     /* shared constants */
    &be_const_str_page_extensions_store,
    &be_const_str_solidified,
    ( &(const binstruction[207]) {  /* code */
      0xA4060000,  //  0000  IMPORT	R1	K0
      0xA40A0E00,  //  0001  IMPORT	R2	K7
      0xA40E5600,  //  0002  IMPORT	R3	K43
      0x8C100390,  //  0003  GETMET	R4	R1	K144
      0x541A00C7,  //  0004  LDINT	R6	200
      0x581C0091,  //  0005  LDCONST	R7	K145
      0x7C100600,  //  0006  CALL	R4	3
      0x4C100000,  //  0007  LDNIL	R4
      0xA8020004,  //  0008  EXBLK	0	#000E
      0x8C140192,  //  0009  GETMET	R5	R0	K146
      0x7C140200,  //  000A  CALL	R5	1
      0x5C100A00,  //  000B  MOVE	R4	R5
      0xA8040001,  //  000C  EXBLK	1	1
      0x70020011,  //  000D  JMP		#0020
      0xAC140002,  //  000E  CATCH	R5	0	2
      0x7002000E,  //  000F  JMP		#001F
      0x8C1C0339,  //  0010  GETMET	R7	R1	K57
      0x58240093,  //  0011  LDCONST	R9	K147
      0x7C1C0400,  //  0012  CALL	R7	2
      0x8C1C0339,  //  0013  GETMET	R7	R1	K57
      0x60240018,  //  0014  GETGBL	R9	G24
      0x58280094,  //  0015  LDCONST	R10	K148
      0x8C2C0364,  //  0016  GETMET	R11	R1	K100
      0x5C340C00,  //  0017  MOVE	R13	R6
      0x7C2C0400,  //  0018  CALL	R11	2
      0x7C240400,  //  0019  CALL	R9	2
      0x7C1C0400,  //  001A  CALL	R7	2
      0x8C1C0395,  //  001B  GETMET	R7	R1	K149
      0x7C1C0200,  //  001C  CALL	R7	1
      0x80000E00,  //  001D  RET	0
      0x70020000,  //  001E  JMP		#0020
      0xB0080000,  //  001F  RAISE	2	R0	R0
      0x8C140596,  //  0020  GETMET	R5	R2	K150
      0x5C1C0800,  //  0021  MOVE	R7	R4
      0x58200097,  //  0022  LDCONST	R8	K151
      0x7C140600,  //  0023  CALL	R5	3
      0x8C180339,  //  0024  GETMET	R6	R1	K57
      0x58200098,  //  0025  LDCONST	R8	K152
      0x7C180400,  //  0026  CALL	R6	2
      0x8C180339,  //  0027  GETMET	R6	R1	K57
      0x60200018,  //  0028  GETGBL	R8	G24
      0x58240099,  //  0029  LDCONST	R9	K153
      0x5C280A00,  //  002A  MOVE	R10	R5
      0x7C200400,  //  002B  CALL	R8	2
      0x7C180400,  //  002C  CALL	R6	2
      0x8C180339,  //  002D  GETMET	R6	R1	K57
      0x5820009A,  //  002E  LDCONST	R8	K154
      0x7C180400,  //  002F  CALL	R6	2
      0x8C180112,  //  0030  GETMET	R6	R0	K18
      0x7C180200,  //  0031  CALL	R6	1
      0x581C0020,  //  0032  LDCONST	R7	K32
      0x5820000F,  //  0033  LDCONST	R8	K15
      0x6024000C,  //  0034  GETGBL	R9	G12
      0x5C280800,  //  0035  MOVE	R10	R4
      0x7C240200,  //  0036  CALL	R9	1
      0x14241009,  //  0037  LT	R9	R8	R9
      0x7826008F,  //  0038  JMPF	R9	#00C9
      0x8C240513,  //  0039  GETMET	R9	R2	K19
      0x5C2C0800,  //  003A  MOVE	R11	R4
      0x5830009B,  //  003B  LDCONST	R12	K155
      0x5C341000,  //  003C  MOVE	R13	R8
      0x7C240800,  //  003D  CALL	R9	4
      0x1428130F,  //  003E  LT	R10	R9	K15
      0x782A0003,  //  003F  JMPF	R10	#0044
      0x6028000C,  //  0040  GETGBL	R10	G12
      0x5C2C0800,  //  0041  MOVE	R11	R4
      0x7C280200,  //  0042  CALL	R10	1
      0x5C241400,  //  0043  MOVE	R9	R10
      0x40281009,  //  0044  CONNECT	R10	R8	R9
      0x9428080A,  //  0045  GETIDX	R10	R4	R10
      0x8C2C019C,  //  0046  GETMET	R11	R0	K156
      0x5C341400,  //  0047  MOVE	R13	R10
      0x7C2C0400,  //  0048  CALL	R11	2
      0x4C300000,  //  0049  LDNIL	R12
      0x2030160C,  //  004A  NE	R12	R11	R12
      0x78320079,  //  004B  JMPF	R12	#00C6
      0x94301733,  //  004C  GETIDX	R12	R11	K51
      0x8C34019D,  //  004D  GETMET	R13	R0	K157
      0x5C3C1800,  //  004E  MOVE	R15	R12
      0x7C340400,  //  004F  CALL	R13	2
      0x8C380364,  //  0050  GETMET	R14	R1	K100
      0x94401731,  //  0051  GETIDX	R16	R11	K49
      0x7C380400,  //  0052  CALL	R14	2
      0x943C1732,  //  0053  GETIDX	R15	R11	K50
      0x8C40059E,  //  0054  GETMET	R16	R2	K158
      0x8C480364,  //  0055  GETMET	R18	R1	K100
      0x94501735,  //  0056  GETIDX	R20	R11	K53
      0x7C480400,  //  0057  CALL	R18	2
      0x584C009F,  //  0058  LDCONST	R19	K159
      0x585000A0,  //  0059  LDCONST	R20	K160
      0x7C400800,  //  005A  CALL	R16	4
      0x94441737,  //  005B  GETIDX	R17	R11	K55
      0x50480000,  //  005C  LDBOOL	R18	0	0
      0x4C4C0000,  //  005D  LDNIL	R19
      0x4C500000,  //  005E  LDNIL	R20
      0x8C540111,  //  005F  GETMET	R21	R0	K17
      0x945C1732,  //  0060  GETIDX	R23	R11	K50
      0x7C540400,  //  0061  CALL	R21	2
      0x5C502A00,  //  0062  MOVE	R20	R21
      0x8C540364,  //  0063  GETMET	R21	R1	K100
      0x5C5C2800,  //  0064  MOVE	R23	R20
      0x7C540400,  //  0065  CALL	R21	2
      0x8C580D30,  //  0066  GETMET	R22	R6	K48
      0x5C602800,  //  0067  MOVE	R24	R20
      0x7C580400,  //  0068  CALL	R22	2
      0x5C482C00,  //  0069  MOVE	R18	R22
      0x784A000B,  //  006A  JMPF	R18	#0077
      0x94580C14,  //  006B  GETIDX	R22	R6	R20
      0xB85E1000,  //  006C  GETNGBL	R23	K8
      0x8C5C2F3D,  //  006D  GETMET	R23	R23	K61
      0x5C642C00,  //  006E  MOVE	R25	R22
      0x7C5C0400,  //  006F  CALL	R23	2
      0x60600009,  //  0070  GETGBL	R24	G9
      0x8C642F13,  //  0071  GETMET	R25	R23	K19
      0x586C0033,  //  0072  LDCONST	R27	K51
      0x5870000F,  //  0073  LDCONST	R28	K15
      0x7C640600,  //  0074  CALL	R25	3
      0x7C600200,  //  0075  CALL	R24	1
      0x5C4C3000,  //  0076  MOVE	R19	R24
      0x784A0001,  //  0077  JMPF	R18	#007A
      0x1458260C,  //  0078  LT	R22	R19	R12
      0x745A0000,  //  0079  JMPT	R22	#007B
      0x50580001,  //  007A  LDBOOL	R22	0	1
      0x50580200,  //  007B  LDBOOL	R22	1	0
      0x8C5C0339,  //  007C  GETMET	R23	R1	K57
      0x60640018,  //  007D  GETGBL	R25	G24
      0x586800A1,  //  007E  LDCONST	R26	K161
      0x5C6C0E00,  //  007F  MOVE	R27	R7
      0x5C701C00,  //  0080  MOVE	R28	R14
      0x8C74019D,  //  0081  GETMET	R29	R0	K157
      0x5C7C1800,  //  0082  MOVE	R31	R12
      0x7C740400,  //  0083  CALL	R29	2
      0x7C640800,  //  0084  CALL	R25	4
      0x7C5C0400,  //  0085  CALL	R23	2
      0x785A0003,  //  0086  JMPF	R22	#008B
      0x8C5C0339,  //  0087  GETMET	R23	R1	K57
      0x586400A2,  //  0088  LDCONST	R25	K162
      0x7C5C0400,  //  0089  CALL	R23	2
      0x70020003,  //  008A  JMP		#008F
      0x784A0002,  //  008B  JMPF	R18	#008F
      0x8C5C0339,  //  008C  GETMET	R23	R1	K57
      0x586400A3,  //  008D  LDCONST	R25	K163
      0x7C5C0400,  //  008E  CALL	R23	2
      0x8C5C0339,  //  008F  GETMET	R23	R1	K57
      0x60640018,  //  0090  GETGBL	R25	G24
      0x586800A4,  //  0091  LDCONST	R26	K164
      0x5C6C0E00,  //  0092  MOVE	R27	R7
      0x5C700E00,  //  0093  MOVE	R28	R7
      0x5C742000,  //  0094  MOVE	R29	R16
      0x7C640800,  //  0095  CALL	R25	4
      0x7C5C0400,  //  0096  CALL	R23	2
      0x785A0008,  //  0097  JMPF	R22	#00A1
      0x8C5C0339,  //  0098  GETMET	R23	R1	K57
      0x60640018,  //  0099  GETGBL	R25	G24
      0x586800A5,  //  009A  LDCONST	R26	K165
      0x8C6C019D,  //  009B  GETMET	R27	R0	K157
      0x5C742600,  //  009C  MOVE	R29	R19
      0x7C6C0400,  //  009D  CALL	R27	2
      0x5C701A00,  //  009E  MOVE	R28	R13
      0x7C640600,  //  009F  CALL	R25	3
      0x7C5C0400,  //  00A0  CALL	R23	2
      0x8C5C0339,  //  00A1  GETMET	R23	R1	K57
      0x586400A6,  //  00A2  LDCONST	R25	K166
      0x7C5C0400,  //  00A3  CALL	R23	2
      0x784A0013,  //  00A4  JMPF	R18	#00B9
      0x785A0007,  //  00A5  JMPF	R22	#00AE
      0x8C5C0339,  //  00A6  GETMET	R23	R1	K57
      0x60640018,  //  00A7  GETGBL	R25	G24
      0x586800A7,  //  00A8  LDCONST	R26	K167
      0x5C6C2A00,  //  00A9  MOVE	R27	R21
      0x5C702A00,  //  00AA  MOVE	R28	R21
      0x7C640600,  //  00AB  CALL	R25	3
      0x7C5C0400,  //  00AC  CALL	R23	2
      0x70020002,  //  00AD  JMP		#00B1
      0x8C5C0339,  //  00AE  GETMET	R23	R1	K57
      0x586400A8,  //  00AF  LDCONST	R25	K168
      0x7C5C0400,  //  00B0  CALL	R23	2
      0x8C5C0339,  //  00B1  GETMET	R23	R1	K57
      0x60640018,  //  00B2  GETGBL	R25	G24
      0x586800A9,  //  00B3  LDCONST	R26	K169
      0x5C6C2A00,  //  00B4  MOVE	R27	R21
      0x5C702A00,  //  00B5  MOVE	R28	R21
      0x7C640600,  //  00B6  CALL	R25	3
      0x7C5C0400,  //  00B7  CALL	R23	2
      0x70020008,  //  00B8  JMP		#00C2
      0x8C5C0339,  //  00B9  GETMET	R23	R1	K57
      0x60640018,  //  00BA  GETGBL	R25	G24
      0x586800AA,  //  00BB  LDCONST	R26	K170
      0x5C6C2A00,  //  00BC  MOVE	R27	R21
      0x5C701C00,  //  00BD  MOVE	R28	R14
      0x5C742A00,  //  00BE  MOVE	R29	R21
      0x5C781C00,  //  00BF  MOVE	R30	R14
      0x7C640A00,  //  00C0  CALL	R25	5
      0x7C5C0400,  //  00C1  CALL	R23	2
      0x8C5C0339,  //  00C2  GETMET	R23	R1	K57
      0x58640080,  //  00C3  LDCONST	R25	K128
      0x7C5C0400,  //  00C4  CALL	R23	2
      0x001C0F20,  //  00C5  ADD	R7	R7	K32
      0x00301320,  //  00C6  ADD	R12	R9	K32
      0x5C201800,  //  00C7  MOVE	R8	R12
      0x7001FF6A,  //  00C8  JMP		#0034
      0x8C240339,  //  00C9  GETMET	R9	R1	K57
      0x582C0082,  //  00CA  LDCONST	R11	K130
      0x7C240400,  //  00CB  CALL	R9	2
      0x8C240395,  //  00CC  GETMET	R9	R1	K149
      0x7C240200,  //  00CD  CALL	R9	1
      0x80000000,  //  00CE  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified class: Extension_manager
********************************************************************/
be_local_class(Extension_manager,
    0,
    NULL,
    be_nested_map(24,
    ( (struct bmapnode*) &(const bmapnode[]) {
        { be_const_key(page_extensions_mgr_dispatcher, 22), be_const_closure(class_Extension_manager_page_extensions_mgr_dispatcher_closure) },
        { be_const_key(ext_repo_local, -1), be_const_static_closure(class_Extension_manager_ext_repo_local_closure) },
        { be_const_key(delete_ext, 4), be_const_static_closure(class_Extension_manager_delete_ext_closure) },
        { be_const_key(EXT_REPO_MANIFEST, 5), be_nested_str(extensions_X2Ejsonl) },
        { be_const_key(web_add_handler, -1), be_const_closure(class_Extension_manager_web_add_handler_closure) },
        { be_const_key(run_stop_ext, 7), be_const_static_closure(class_Extension_manager_run_stop_ext_closure) },
        { be_const_key(check_or_create_dir, -1), be_const_static_closure(class_Extension_manager_check_or_create_dir_closure) },
        { be_const_key(init, -1), be_const_closure(class_Extension_manager_init_closure) },
        { be_const_key(list_extensions, -1), be_const_static_closure(class_Extension_manager_list_extensions_closure) },
        { be_const_key(version_string, -1), be_const_static_closure(class_Extension_manager_version_string_closure) },
        { be_const_key(load_manifest, -1), be_const_closure(class_Extension_manager_load_manifest_closure) },
        { be_const_key(EXT_REPO_FOLDER, -1), be_nested_str(tapp_X2F) },
        { be_const_key(list_extensions_in_fs, -1), be_const_static_closure(class_Extension_manager_list_extensions_in_fs_closure) },
        { be_const_key(EXT_REPO, 9), be_nested_str(https_X3A_X2F_X2Fota_X2Etasmota_X2Ecom_X2Fextensions_X2F) },
        { be_const_key(page_extensions_ctl, -1), be_const_closure(class_Extension_manager_page_extensions_ctl_closure) },
        { be_const_key(install_from_store, 14), be_const_closure(class_Extension_manager_install_from_store_closure) },
        { be_const_key(page_extensions_mgr, -1), be_const_closure(class_Extension_manager_page_extensions_mgr_closure) },
        { be_const_key(EXT_FOLDER, 13), be_nested_str(_X2F_X2Eextensions_X2F) },
        { be_const_key(web_add_button, 11), be_const_closure(class_Extension_manager_web_add_button_closure) },
        { be_const_key(manifest_decode, 10), be_const_static_closure(class_Extension_manager_manifest_decode_closure) },
        { be_const_key(list_installed_ext, -1), be_const_static_closure(class_Extension_manager_list_installed_ext_closure) },
        { be_const_key(enable_disable_ext, -1), be_const_static_closure(class_Extension_manager_enable_disable_ext_closure) },
        { be_const_key(tapp_name, -1), be_const_static_closure(class_Extension_manager_tapp_name_closure) },
        { be_const_key(page_extensions_store, -1), be_const_closure(class_Extension_manager_page_extensions_store_closure) },
    })),
    (bstring*) &be_const_str_Extension_manager
);

/********************************************************************
** Solidified function: _anonymous_
********************************************************************/
be_local_closure(_anonymous_,   /* name */
  be_nested_proto(
    3,                          /* nstack */
    1,                          /* argc */
    0,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    ( &(const bvalue[ 1]) {     /* constants */
    /* K0   */  be_nested_str(Extension_manager),
    }),
    &be_const_str__anonymous_,
    &be_const_str_solidified,
    ( &(const binstruction[ 3]) {  /* code */
      0x8C040100,  //  0000  GETMET	R1	R0	K0
      0x7C040200,  //  0001  CALL	R1	1
      0x80040200,  //  0002  RET	1	R1
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified module: extension_manager
********************************************************************/
be_local_module(extension_manager,
    "extension_manager",
    be_nested_map(2,
    ( (struct bmapnode*) &(const bmapnode[]) {
        { be_const_key(Extension_manager, -1), be_const_class(be_class_Extension_manager) },
        { be_const_key(init, -1), be_const_closure(_anonymous__closure) },
    }))
);
BE_EXPORT_VARIABLE be_define_const_native_module(extension_manager);
/********************************************************************/
/********************************************************************/
/* End of solidification */
