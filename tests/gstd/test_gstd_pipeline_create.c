#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <gst/check/gstcheck.h>

#include "gstd_session.h"


GST_START_TEST (test_pipeline_create_successful)
{
  GstdObject *node;
  GstdReturnCode ret;
  GstdSession *test_session = gstd_session_new ("Test_session");

  ret = gstd_get_by_uri (test_session, "/pipelines", &node);
  fail_if (ret);
  fail_if (NULL == node);

  ret = gstd_object_create (node, "p0", "fakesrc ! fakesink");
  fail_if (GSTD_EOK != ret);

  gst_object_unref(node);
  gst_object_unref(test_session);
}
GST_END_TEST;


GST_START_TEST (test_pipeline_create_no_name)
{
  GstdObject *node;
  GstdReturnCode ret;
  GstdSession *test_session = gstd_session_new ("Test_session");

  ret = gstd_get_by_uri (test_session, "/pipelines", &node);
  fail_if (ret);
  fail_if (NULL == node);

  ret = gstd_object_create (node, NULL, NULL);
  fail_if (GSTD_MISSING_NAME != ret);

  gst_object_unref(node);
  gst_object_unref(test_session);
}
GST_END_TEST;


GST_START_TEST (test_pipeline_create_no_description)
{
  GstdObject *node;
  GstdReturnCode ret;
  GstdSession *test_session = gstd_session_new ("Test_session");

  ret = gstd_get_by_uri (test_session, "/pipelines", &node);
  fail_if (ret);
  fail_if (NULL == node);

  ret = gstd_object_create (node, "p2", NULL);
  fail_if (GSTD_MISSING_ARGUMENT != ret);

  gst_object_unref(node);
  gst_object_unref(test_session);
}
GST_END_TEST;


GST_START_TEST (test_pipeline_create_erroneous_description)
{
  GstdObject *node;
  GstdReturnCode ret;
  GstdSession *test_session = gstd_session_new ("Test_session");

  ret = gstd_get_by_uri (test_session, "/pipelines", &node);
  fail_if (ret);
  fail_if (NULL == node);

  ret = gstd_object_create (node, "p3", "fakesrc !");
  fail_if (GSTD_BAD_DESCRIPTION != ret);

  gst_object_unref(node);
  gst_object_unref(test_session);
}
GST_END_TEST;


static Suite *
gstd_pipeline_create_suite (void)
{
  Suite *suite = suite_create ("gstd_pipeline_create");
  TCase *tc = tcase_create ("general");

  suite_add_tcase (suite, tc);
  tcase_add_test (tc, test_pipeline_create_successful);
  tcase_add_test (tc, test_pipeline_create_no_name);
  tcase_add_test (tc, test_pipeline_create_no_description);
  tcase_add_test (tc, test_pipeline_create_erroneous_description);

  return suite;
}

GST_CHECK_MAIN (gstd_pipeline_create);
